# Напишете скрипт manage.sh, който управлява сървиси. Скриптът очаква да съществува environment
# променливата SVC_DIR, съдържаща име на директория, в която се намират описанията на сървисите.
# Всеки обикновен файл в SVC_DIR описва един сървис (имената на файловете не ни интересуват).
# Файловете имат следния
# вид:
# name: <име на сървис>
# pidfile: <име на pid файл>
# outfile: <име на файл>
# comm: <shell команда>
# Примерен файл (наредбата на редовете няма значе-
# ние):
# comm: while true; do echo ZzZ; sleep 1; done
# outfile: /tmp/sleeper_out
# pidfile: /tmp/sleeper_pid
# name: sleeper
# manage.sh трябва да може да се извиква по следните начини:
# • ./manage.sh start <име на сървис> – стартира дадения сървис, което означава:
# – Стартира процес: shell, изпълняващ командата (comm) на дадения сървис във фонов режим
# – Записва PID-а на стартирания процес в съответния pidfile
# – Пренасочва stdout и stderr в изходния файл (outfile)
# – Ако сървисът вече работи, вместо гореизброените стъпки, start не прави нищо
# • ./manage.sh stop <име на сървис> – убива процеса на сървиса със SIGTERM
# • ./manage.sh running – изписва имената на всички сървиси, чиито процеси (спрямо pidfile)
# още работят, по едно на ред, сортирани лексикографски
# • ./manage.sh cleanup – изтрива PID-файловете на всички сървиси, чиито процеси не същест-
# вуват
# Примерно извикване: ./manage.sh start sleeper


#!/bin/bash

# Проверка за SVC_DIR environment променлива
if [ -z "$SVC_DIR" ]; then
    echo "Грешка: Environment променливата SVC_DIR не е зададена."
    exit 1
fi

if [ ! -d "$SVC_DIR" ]; then
    echo "Грешка: Директорията '$SVC_DIR' не съществува."
    exit 1
fi

# Функция за парсиране на сървис файл
parse_service_file() {
    local service_file="$1"
    local -n service_data="$2"
    
    # Инициализиране на асоциативен масив
    service_data["name"]=""
    service_data["pidfile"]=""
    service_data["outfile"]=""
    service_data["comm"]=""
    
    while IFS=': ' read -r key value || [[ -n "$key" ]]; do
        # Пропускане на празни редове и коментари
        if [[ -z "$key" ]] || [[ "$key" =~ ^[[:space:]]*# ]]; then
            continue
        fi
        
        # Премахване на водещи/следващи интервали
        key=$(echo "$key" | xargs)
        value=$(echo "$value" | xargs)
        
        case "$key" in
            "name"|"pidfile"|"outfile"|"comm")
                service_data["$key"]="$value"
                ;;
        esac
    done < "$service_file"
}

# Функция за намиране на сървис файл по име
find_service_file() {
    local service_name="$1"
    
    for file in "$SVC_DIR"/*; do
        if [ -f "$file" ]; then
            declare -A service_info
            parse_service_file "$file" service_info
            
            if [ "${service_info[name]}" = "$service_name" ]; then
                echo "$file"
                return 0
            fi
        fi
    done
    
    return 1
}

# Функция за проверка дали процес работи
is_process_running() {
    local pid="$1"
    if [ -z "$pid" ]; then
        return 1
    fi
    
    kill -0 "$pid" 2>/dev/null
    return $?
}

# Функция за стартиране на сървис
start_service() {
    local service_name="$1"
    
    local service_file
    service_file=$(find_service_file "$service_name")
    
    if [ $? -ne 0 ]; then
        echo "Грешка: Сървис '$service_name' не е намерен."
        exit 1
    fi
    
    declare -A service_info
    parse_service_file "$service_file" service_info
    
    # Проверка дали всички необходими полета са попълнени
    if [ -z "${service_info[name]}" ] || [ -z "${service_info[pidfile]}" ] || \
       [ -z "${service_info[outfile]}" ] || [ -z "${service_info[comm]}" ]; then
        echo "Грешка: Файлът на сървис '$service_name' не съдържа всички необходими полета."
        exit 1
    fi
    
    # Проверка дали сървисът вече работи
    if [ -f "${service_info[pidfile]}" ]; then
        local existing_pid
        existing_pid=$(cat "${service_info[pidfile]}" 2>/dev/null)
        
        if is_process_running "$existing_pid"; then
            echo "Сървис '$service_name' вече работи с PID $existing_pid."
            return 0
        fi
    fi
    
    # Създаване на директориите за файловете, ако не съществуват
    mkdir -p "$(dirname "${service_info[pidfile]}")" 2>/dev/null
    mkdir -p "$(dirname "${service_info[outfile]}")" 2>/dev/null
    
    # Стартиране на процеса във фонов режим
    nohup bash -c "${service_info[comm]}" > "${service_info[outfile]}" 2>&1 &
    local service_pid=$!
    
    # Записване на PID в файла
    echo "$service_pid" > "${service_info[pidfile]}"
    
    echo "Сървис '$service_name' стартиран с PID $service_pid."
}

# Функция за спиране на сървис
stop_service() {
    local service_name="$1"
    
    local service_file
    service_file=$(find_service_file "$service_name")
    
    if [ $? -ne 0 ]; then
        echo "Грешка: Сървис '$service_name' не е намерен."
        exit 1
    fi
    
    declare -A service_info
    parse_service_file "$service_file" service_info
    
    if [ ! -f "${service_info[pidfile]}" ]; then
        echo "Сървис '$service_name' не работи (няма PID файл)."
        return 0
    fi
    
    local pid
    pid=$(cat "${service_info[pidfile]}" 2>/dev/null)
    
    if ! is_process_running "$pid"; then
        echo "Сървис '$service_name' не работи (процесът не съществува)."
        rm -f "${service_info[pidfile]}"
        return 0
    fi
    
    # Изпращане на SIGTERM
    kill -TERM "$pid" 2>/dev/null
    
    if [ $? -eq 0 ]; then
        echo "Сървис '$service_name' спрян (PID $pid)."
        rm -f "${service_info[pidfile]}"
    else
        echo "Грешка при спиране на сървис '$service_name'."
        exit 1
    fi
}

# Функция за показване на работещи сървиси
show_running() {
    local running_services=()
    
    for file in "$SVC_DIR"/*; do
        if [ -f "$file" ]; then
            declare -A service_info
            parse_service_file "$file" service_info
            
            if [ -n "${service_info[name]}" ] && [ -f "${service_info[pidfile]}" ]; then
                local pid
                pid=$(cat "${service_info[pidfile]}" 2>/dev/null)
                
                if is_process_running "$pid"; then
                    running_services+=("${service_info[name]}")
                fi
            fi
        fi
    done
    
    # Сортиране и показване
    if [ ${#running_services[@]} -gt 0 ]; then
        printf '%s\n' "${running_services[@]}" | sort
    fi
}

# Функция за почистване на PID файлове
cleanup_services() {
    local cleaned_count=0
    
    for file in "$SVC_DIR"/*; do
        if [ -f "$file" ]; then
            declare -A service_info
            parse_service_file "$file" service_info
            
            if [ -n "${service_info[pidfile]}" ] && [ -f "${service_info[pidfile]}" ]; then
                local pid
                pid=$(cat "${service_info[pidfile]}" 2>/dev/null)
                
                if ! is_process_running "$pid"; then
                    rm -f "${service_info[pidfile]}"
                    echo "Изтрит PID файл за сървис '${service_info[name]}' (PID $pid не съществува)."
                    ((cleaned_count++))
                fi
            fi
        fi
    done
    
    if [ $cleaned_count -eq 0 ]; then
        echo "Няма PID файлове за почистване."
    else
        echo "Почистени $cleaned_count PID файл(а)."
    fi
}

# Главна логика
case "$1" in
    "start")
        if [ $# -ne 2 ]; then
            echo "Използване: $0 start <име_на_сървис>"
            exit 1
        fi
        start_service "$2"
        ;;
    "stop")
        if [ $# -ne 2 ]; then
            echo "Използване: $0 stop <име_на_сървис>"
            exit 1
        fi
        stop_service "$2"
        ;;
    "running")
        if [ $# -ne 1 ]; then
            echo "Използване: $0 running"
            exit 1
        fi
        show_running
        ;;
    "cleanup")
        if [ $# -ne 1 ]; then
            echo "Използване: $0 cleanup"
            exit 1
        fi
        cleanup_services
        ;;
    *)
        echo "Използване: $0 {start|stop|running|cleanup} [сървис]"
        echo ""
        echo "Команди:"
        echo "  start <сървис>  - стартира сървис"
        echo "  stop <сървис>   - спира сървис"
        echo "  running         - показва работещи сървиси"
        echo "  cleanup         - почиства PID файлове на неработещи сървиси"
        exit 1
        ;;
esac