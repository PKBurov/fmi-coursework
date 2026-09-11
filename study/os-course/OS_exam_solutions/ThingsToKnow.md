# Bash Reference Guide

## Файлова работа

```bash
find /path -name "*.ext"
basename /path/to/file.ext # -> file.ext
dirname /path/to/file.ext # -> /path/to
```

## Текстова обработка

```bash
sed 's/old/new/g' file
awk -F'=' '{print $1, $2}' file
grep "pattern" file
```

## String операции

```bash
${var#pattern}   # премахва от началото
${var%pattern}   # премахва от края
${var/old/new}   # замества първото
${var//old/new}  # замества всички
```

## Масиви

```bash
# Обикновени масиви
arr=(a b c)
${arr[@]}    # всички елементи
${#arr[@]}   # брой елементи

# Асоциативни масиви
declare -A array
array["key"]="value"
if [[ -n "${array[key]}" ]]; then
    echo "Key exists"
fi
```

## Bash основи (КРИТИЧНО - за задачи 1-6)

### Променливи и аргументи
```bash
$1, $2, $#, $@, $*
VARIABLE="value"
${VARIABLE}
```

### Условни конструкции
```bash
if [ условие ]; then
    # код
fi
```

### Цикли
```bash
for item in list; do
    # код
done

while read line; do
    # код
done
```

## Асоциативни масиви в bash (за задача 1 - PrevCloud)

```bash
declare -A users
users["john"]="enabled"
users["mary"]="disabled"

# Проверка дали ключ съществува
if [[ -n "${users[john]}" ]]; then
    echo "John exists"
fi
```

## Файлови операции (за всички задачи)

### Проверки
```bash
[ -f file ]  # файл съществува
[ -d dir ]   # директория съществува
[ -e path ]  # нещо съществува
```

### Четене на файлове
```bash
while IFS= read -r line; do
    echo "$line"
done < file
```

## String manipulation (за задачи 3, 5)

### Regex matching
```bash
if [[ "$string" =~ pattern ]]; then
    echo "${BASH_REMATCH[1]}" # първата група
fi

# Пример за нотите
if [[ "$string" =~ \[([A-G][b#]?)[^\]]* ]]; then
    note="${BASH_REMATCH[1]}"
fi
```

### Замествания
```bash
${var/old/new}   # замести първото
${var//old/new}  # замести всички
```

## Работа с външни програми

```bash
# Извикване и вземане на изход
output=$(command)
output=$(./program arg1 arg2)

# Проверка на статуса
if [ $? -eq 0 ]; then
    echo "Success"
fi
```

## Важни команди за изучаване

- **sed** (search and replace)
- **awk** (pattern processing)
- **grep** (pattern matching)
- **find** (file searching)
- **sort, uniq**

## Важни концепции за изучаване

- Променливи и quoting
- if/then/else/fi конструкции
- for/while цикли
- Функции
- Масиви (обикновени и асоциативни)
- Regex patterns
- Файлова работа и stream processing

# Проверка на exit status
if command; then
    echo "success"
fi