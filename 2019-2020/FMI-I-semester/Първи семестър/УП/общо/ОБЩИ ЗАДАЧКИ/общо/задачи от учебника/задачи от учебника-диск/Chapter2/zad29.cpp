#include <iostream.h>

int main()
{ 
    int day, month, year;
    int dayCount;
    cout << "day= "; 
    cin >> day;
    cout << "month= "; 
    cin >> month;
    cout << "year= "; 
    cin >> year;

    bool isValid;
    isValid = (year >= 1900) && (year <= 9999) &&
              (month >= 1) && (month <= 12) &&
              (day >= 1) && (day <= 31);
    if(isValid)
    { 
        bool isLeapYear = ((year % 4 == 0) && (year % 100 != 0)) ||
                           (year % 400 == 0);
        if(month == 2)
        {
            dayCount = 28 + isLeapYear;
        }
        else
        {
            if(month <= 7)
            {
                dayCount = 30 + (month % 2);
            }
            else
            {
                dayCount = 31 - (month % 2);
            }
        }
        if(day > dayCount)
        {
            isValid = false;
        }
    }
    if(isValid)
    {
        cout << "Въведената дата е валидна.\n";
    }
    else
    {
        cout << "Въведената дата е невалидна.\n";
    }
    return 0;
}
