#include <iostream.h>

int main()
{
    int month, year;
    int dayCount;
    cout << "month= ";
    cin >> month;
    cout << "year= ";
    cin >> year;
    
    bool isLeapYear = ((year % 4 == 0) && (year % 100 != 0)) ||
                       (year % 400 == 0);

    if(month == 2)
    {
        dayCount = 28 + isLeapYear;
    }
    else if(month <= 7)
    {
        dayCount = 30 + (month % 2);
    }
    else
    {
        dayCount = 31 - (month % 2);
    }

    cout << "Броят на дните в месец " << month << " на "
         << year << " e " << dayCount << endl;
    return 0;
}
