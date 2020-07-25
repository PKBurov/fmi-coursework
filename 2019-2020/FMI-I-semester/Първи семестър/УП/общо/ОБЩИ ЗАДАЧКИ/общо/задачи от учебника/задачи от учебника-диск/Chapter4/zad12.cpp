#include <iostream.h>

// Проверява дали година е високосна
bool isLeap(int year)
{
    return (!(year % 400) || ((year % 100) && !(year % 4)));
}	

// пресмята броя на дните в даден месец
// проверява дали датата е от високосна
// или от невисокосна година
int maxDays(int month, bool leapYear)
{
    leapYear &= (month == 2);
    int day = (month == 2) ? 28 : 31;
    if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    return leapYear ? 29 : day;
}

// проверява дали датата е коректна
// връща различни стойности в зависимост
// от причината за некоректност на датата
int chkDate(int day, int month, int year)
{
    if(year < 0 || year > 2007)
    {
        return 3;
    }
    if(month <= 0 || month > 12)
    {
        return 2;
    }
    if(day <= 0 || day > maxDays(month, isLeap(year)))
    {
        return 1;
    }
    return 0;
}

void printResult(int status)
{ 
    switch(status)
    { 
    case 0:
        cout << "Датата е коректна." << endl;
        break;
    case 1:
        cout << "Грешка! Неправилен е денят." << endl;
        break;
    case 2:
        cout << "Грешка! Неправилен е месецът." << endl;
        break;
    case 3:
        cout << "Грешка! Неправилна е годината." << endl;
        break;
    }
}

int main()
{ 
    int m, d, y;
    cout << "Въведете дата(dd mm yyyy): ";
    cin >> d >> m >> y;
    int status = chkDate(d, m, y);
    printResult(status);
    return 0;
}
