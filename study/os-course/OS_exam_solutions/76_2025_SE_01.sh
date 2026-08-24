# 2025-SE-01
# Ваш бивш съученик, с когото не сте се чували от 11 години, се свързва с вас и спешно иска помощ с
# автоматизация на използването на външния инструмент ANTLR, който вие имате вече инсталиран
# на компютъра си.

# Напишете скрипт build.sh, който се управлява с конфигурационни файлове, имащи следния вид:
# <език> <желани типове изходни файлове> '<базова изходна директория>'

# Примерен такъв конфигурационен файл:
# Go recognizer listener '/foo'
# JavaScript visitor recognizer '/bar'
# Java listener recognizer visitor '/baz' 

# build.sh трябва да приема два аргумента:
    # • Име на конфигурационен файл (подобен на примерния от по-горе)
    # • Име на входен файл (съдържанието му не ни интересува)

# build.sh трябва да извика ANTLR по веднъж за всеки ред от конфигурационния файл, така че да
# създаде нужните изходни файлове в съответните изходни директории.

# Извикването става по следния начин:
# antlr4 -Dlanguage=<език> <опции> -o <изходна директория> <входен файл>

# Изходната директория трябва да е поддиректория с име, съответстващо на името на входния файл,
# но без разширение, и намираща се в базовата изходна директория.

# Инструментът ANTLR генерира изходни файлове спрямо следните правила:
    # • Recognizer файловете се генерират винаги
    # • Listener файловете се генерират ако не е подадена опция -no-listener
    # • Visitor файловете се генерират ако е подадена опция -visitor

# Ако приемем, че конфигурационният файл се казва Antlrfile, примерното извикване
    # ./build.sh Antlrfile grammar/Query.g4

# трябва да доведе до извикване на следните команди:
    # antlr4 -Dlanguage=Go -o /foo/Query grammar/Query.g4
    # antlr4 -Dlanguage=JavaScript -no-listener -visitor -o /bar/Query grammar/Query.g4
    # antlr4 -Dlanguage=Java -visitor -o /baz/Query grammar/Query.g4
    # ANTLR сам ще се погрижи да създаде нужните файлове в съответните изходни директории.


## Solution ## 

#!/bin/bash

# Проверка на аргументите
if [ $# -ne 2 ]; then
    echo "Използване: $0 <кoнфигурационен_файл> <входен_файл>"
    echo "Пример: $0 Antlrfile grammar/Query.g4"
    exit 1
fi

CONFIG_FILE="$1"
INPUT_FILE="$2"

# Проверка дали конфигурационният файл съществува
if [ ! -f "$CONFIG_FILE" ]; then
    echo "Грешка: Конфигурационният файл '$CONFIG_FILE' не съществува."
    exit 1
fi

# Проверка дали входният файл съществува
if [ ! -f "$INPUT_FILE" ]; then
    echo "Грешка: Входният файл '$INPUT_FILE' не съществува."
    exit 1
fi

# Извличане на името на файла без разширение от пътя
INPUT_BASENAME=$(basename "$INPUT_FILE")
INPUT_NAME="${INPUT_BASENAME%.*}"

echo "Обработка на файл: $INPUT_FILE"
echo "Изходно име: $INPUT_NAME"
echo ""

# Четене и обработка на всеки ред от конфигурационния файл
while IFS= read -r line || [[ -n "$line" ]]; do
    # Пропускане на празни редове и коментари
    if [[ -z "$line" ]] || [[ "$line" =~ ^[[:space:]]*# ]]; then
        continue
    fi
    
    # Парсиране на реда
    # Формат: <език> <типове> '<базова_директория>'
    if [[ "$line" =~ ^([^[:space:]]+)[[:space:]]+([^']*)'([^']+)'[[:space:]]*$ ]]; then
        LANGUAGE="${BASH_REMATCH[1]}"
        TYPES_STR="${BASH_REMATCH[2]}"
        BASE_DIR="${BASH_REMATCH[3]}"
        
        # Премахване на излишни интервали от типовете
        TYPES_STR=$(echo "$TYPES_STR" | xargs)
        
        # Разделяне на типовете в масив
        read -ra TYPES <<< "$TYPES_STR"
        
        # Създаване на изходната директория
        OUTPUT_DIR="$BASE_DIR/$INPUT_NAME"
        
        # Построяване на опциите за ANTLR
        OPTIONS=""
        
        # Проверка за различните типове файлове
        HAS_VISITOR=false
        HAS_LISTENER=false
        HAS_RECOGNIZER=false
        
        for TYPE in "${TYPES[@]}"; do
            case "$TYPE" in
                "visitor")
                    HAS_VISITOR=true
                    ;;
                "listener")
                    HAS_LISTENER=true
                    ;;
                "recognizer")
                    HAS_RECOGNIZER=true
                    ;;
            esac
        done
        
        # Добавяне на опции според правилата:
        # - Recognizer файловете се генерират винаги
        # - Listener файловете се генерират ако НЕ е подадена опция -no-listener
        # - Visitor файловете се генерират ако Е подадена опция -visitor
        
        if [ "$HAS_VISITOR" = true ]; then
            OPTIONS="$OPTIONS -visitor"
        fi
        
        if [ "$HAS_LISTENER" = false ] && [ "$HAS_VISITOR" = true ]; then
            # Ако искаме само visitor (без listener), добавяме -no-listener
            OPTIONS="$OPTIONS -no-listener"
        fi
        
        # Построяване на командата
        CMD="antlr4 -Dlanguage=$LANGUAGE$OPTIONS -o $OUTPUT_DIR $INPUT_FILE"
        
        echo "Изпълнение: $CMD"
        
        # Изпълнение на командата
        eval "$CMD"
        
        if [ $? -eq 0 ]; then
            echo "Успешно генериране за $LANGUAGE в $OUTPUT_DIR"
        else
            echo "Грешка при генериране за $LANGUAGE"
        fi
        
        echo ""
        
    else
        echo "Предупреждение: Невалиден ред в конфигурационния файл: $line"
    fi
    
done < "$CONFIG_FILE"

echo "Приключено обработване на конфигурационния файл."