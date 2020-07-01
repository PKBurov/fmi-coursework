#include <iostream.h>

int main()
{
    int year;
    cout << "Въведете година: ";
    cin >> year;
    if(((year % 4 == 0) && (year % 100 != 0)) ||  
        (year % 400 == 0))
    {
        cout << "Годината е високосна.\n";
    }
    else
    {
        cout << "Годината не е високосна.\n";
    }
    return 0;
}
