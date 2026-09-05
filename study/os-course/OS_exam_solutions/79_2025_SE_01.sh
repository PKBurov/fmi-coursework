# Софтуерът BOMBA, който ползвате от години, се конфигурира чрез множество текстови файлове, съ-
# държащи редове от вида <ключ>=<стойност>.
# Примерно съдържание на такъв файл:

    # foo=the quick brown fox
    # foo=jumps over the lazy dog
    # bar=123456
    # baz=baba penka
    # bar=789

# За зла беда, новият софтуер BOMBA2 се конфигурира чрез същите ключове и стойности, но с обновен
# синтаксис. Ключовете, имащи повече от една зададена стойност, вече се групират като списъци. Ето
# как би изглеждал примерният файл, преведен до новия формат:
    # foo:
        # - the quick brown fox
        # - jumps over the lazy dog
    # bar:
        # - 123456
        # - 789
    # baz: baba penka

# За да мигрирате по-лесно, напишете скрипт convert_to_bcf2.sh, който приема два аргумента (стара
# директория и нова директория). Всеки обикновен файл в старата директория (и нейните поддирек-
# тории) с име, завършващо с .bcf, трябва:

# • Да се запише в новата директория, запазвайки директорийната структура, но преименувайки
    # файла от <име>.bcf на <име>.bcf2
# • Да се преведе от стария конфигурационен синтаксис до новия

#!/bin/bash

# Проверка на аргументите
if [ $# -ne 2 ]; then
    echo "Използване: $0 <стара_директория> <нова_директория>"
    echo "Пример: $0 /old/config /new/config"
    exit 1
fi

OLD_DIR="$1"
NEW_DIR="$2"

# Проверка дали старата директория съществува
if [ ! -d "$OLD_DIR" ]; then
    echo "Грешка: Старата директория '$OLD_DIR' не съществува."
    exit 1
fi

# Създаване на новата директория, ако не съществува
if [ ! -d "$NEW_DIR" ]; then
    mkdir -p "$NEW_DIR"
    if [ $? -ne 0 ]; then
        echo "Грешка: Не може да се създаде новата директория '$NEW_DIR'."
        exit 1
    fi
fi

# Функция за конвертиране на един файл
convert_file() {
    local input_file="$1"
    local output_file="$2"
    
    echo "Конвертиране: $input_file -> $output_file"
    
    # Създаване на директорията за изходния файл, ако не съществува
    mkdir -p "$(dirname "$output_file")"
    
    # Деклариране на асоциативен масив за съхранение на ключовете и техните стойности
    declare -A config_data
    declare -a key_order  # За запазване на реда на появяване на ключовете
    
    # Четене и парсиране на входния файл
    while IFS= read -r line || [[ -n "$line" ]]; do
        # Пропускане на празни редове и коментари
        if [[ -z "$line" ]] || [[ "$line" =~ ^[[:space:]]*# ]]; then
            continue
        fi
        
        # Парсиране на ред във формат key=value
        if [[ "$line" =~ ^([^=]+)=(.*)$ ]]; then
            local key="${BASH_REMATCH[1]}"
            local value="${BASH_REMATCH[2]}"
            
            # Премахване на водещи и следващи интервали от ключа
            key=$(echo "$key" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')
            
            # Ако ключът вече съществува, добавяме стойността
            if [[ -n "${config_data[$key]}" ]]; then
                config_data[$key]="${config_data[$key]}"$'\n'"$value"
            else
                config_data[$key]="$value"
                key_order+=("$key")
            fi
        fi
    done < "$input_file"
    
    # Генериране на изходния файл в новия формат
    > "$output_file"  # Изчистване на файла
    
    for key in "${key_order[@]}"; do
        local values="${config_data[$key]}"
        
        # Броене на броя стойности за този ключ
        local value_count=$(echo "$values" | wc -l)
        
        if [ "$value_count" -eq 1 ]; then
            # Една стойност - използваме простия синтаксис
            echo "$key: $values" >> "$output_file"
        else
            # Множество стойности - използваме list синтаксиса
            echo "$key:" >> "$output_file"
            
            # Разделяне на стойностите и добавяне на "- " prefix
            while IFS= read -r value; do
                echo "- $value" >> "$output_file"
            done <<< "$values"
        fi
    done
    
    echo "Успешно конвертиран файл: $output_file"
}

# Намиране и обработка на всички .bcf файлове
echo "Търсене на .bcf файлове в '$OLD_DIR'..."

converted_count=0

# Използване на find за намиране на всички .bcf файлове
while IFS= read -r -d '' bcf_file; do
    # Получаване на относителния път от старата директория
    relative_path="${bcf_file#"$OLD_DIR"/}"
    
    # Ако файлът е директно в OLD_DIR (без поддиректория)
    if [[ "$relative_path" == "$bcf_file" ]]; then
        relative_path=$(basename "$bcf_file")
    fi
    
    # Заместване на .bcf с .bcf2
    new_relative_path="${relative_path%.bcf}.bcf2"
    
    # Пълният път до новия файл
    new_file_path="$NEW_DIR/$new_relative_path"
    
    # Конвертиране на файла
    convert_file "$bcf_file" "$new_file_path"
    
    ((converted_count++))
    
done < <(find "$OLD_DIR" -type f -name "*.bcf" -print0)

echo ""
echo "Конвертирани $converted_count файл(а) от '$OLD_DIR' към '$NEW_DIR'."

if [ $converted_count -eq 0 ]; then
    echo "Не са намерени .bcf файлове в '$OLD_DIR'."
else
    echo "Конверсията завършена успешно!"
fi