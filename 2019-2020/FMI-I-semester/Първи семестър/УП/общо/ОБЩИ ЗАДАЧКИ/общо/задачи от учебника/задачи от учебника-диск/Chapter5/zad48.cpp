#include <iostream.h>

const int MAX = 10;

char map[MAX][2];   // Пази съответствието буква - цифра
char num1[MAX], num2[MAX], res[MAX];

// Връща коя цифра съответства на дадената буква.
// -1 ако няма такава буква.
int get_num(char map[][2], char c)
{
    int i = 0;
    while(map[i][0] && map[i][0] != c) 
    {
        i++;
    }
    return map[i][0] == c ? map[i][1] : -1;
}

// Връща дължината на таблицата - т.е.
// броя на различните букви
char get_map_len(char map[][2])
{
    int i = 0;
    while(map[i][0])
    {
        i++;
    }
    return i;
}

// Проверява дали в таблицата се среща дадена цифра.
// Проверката се извършва от началото до индекс to.
bool map_contain(char num, int to)
{
    int i = 0;
    while(i < to && map[i][1] != num)
    {
        ++i;
    }
    return i < to && map[i][1] == num;
}

// Свързва дадена цифра с определена буква.
// Ако тази буква не се е срещала до момента,
// се добавя в таблицата. В противен случай
// се променя стойността й.
void set_num(char map[][2], char c, char num)
{
    int i = 0;
    while(map[i][0] && map[i][0] != c) 
    {
        i++;
    }
    if(map[i][0] == c)
    {
        map[i][1] = num;
    }
    else
    { 
        map[i][0] = c; 
        map[i][1] = num;
        map[i+1][0] = 0;
    }
}

// Добавя буквите на число от ребуса към таблицата 
// със стойност на цифрата 0.
void add_to_map(const char* num)
{
    while(*num)
    { 
        if(get_num(map, *num) < 0)
        {
            set_num(map, *num, 0);
        }
        ++num;
    }
}

// Преобразува низ от ребуса в съответното му число
// взимайки съответните цифри от таблицата.
// Очаква се за всяка буква да има цифра.
unsigned int convert(const char* num)
{
    unsigned res = 0;
    while(*num)
    {
        res = res * 10 + get_num(map, *num);
        num++;
    }
    return res;
}

// Проверява дали дадено разпределение на цифрите
// удовлетворява условията.
bool test()
{ 
    unsigned int n1 = convert(num1);
    unsigned int n2 = convert(num2);
    unsigned int r  = convert(res);
    // Проверява дали всяко число започва с цифра,
    // която не е 0 и дали равенството в ребуса е изпълнено.
    return  get_num(map, *num1) &&
            get_num(map, *num2) &&
            get_num(map, *res) &&
            n1 + n2 == r;
}

// Генерира всички разпределения на цифрите - вариации 
// на 10 елемента от k-ти клас без повторения, където
//  k е броят на различните цифри.
// Числото i е дълбочината на рекурсията.
// Показва за коя подред буква се търси
// съответна незаета до момента цифра.
bool generate_vars(int i, int k)
{
    if(i >= k)                          // Генерирани са всички цифри
        return test();                  // Проверява дали те са решение.
    for(int j = 0; j < 10; ++j)         // Избира се цифра.
    {
        if(!map_contain(j, i))          // Ако не е заета
        {
            map[i][1] = j;              // се свързва с буква
            if(generate_vars(i+1, k))   // следващи свързвания
            {
                return true;
            }
        }
    }
    return false;
}

// Въвежда от клавиатурата елементите на ребуса
void init()
{
    cout << "SEND: "; 
    cin >> num1;
    cout << "MORE: "; 
    cin >> num2;
    cout << "MONEY: ";  
    cin >> res;
}

// Решава ребуса - добавя всички букви от него в таблицата
// и търси решение.
// Ако е намерено решение, връща true, ако не - false
bool solve()
{
    add_to_map(num1);
    add_to_map(num2);
    add_to_map(res);
    return generate_vars(0, get_map_len(map));
}

// Извежда на екрана намереното решение.
void print_solution()
{
    cout << num1 << "\t + \t" 
         << num2 << "\t = \t" 
         << res << endl;
    cout << convert(num1) << "\t + \t" 
         << convert(num2) << "\t = \t"
         << convert(res) << endl;
}

int main()
{
    init();
    if(solve())
    {
        print_solution();
    }
    else
    {
        cout << "Няма решение!\n";
    }
    return 0;
}
