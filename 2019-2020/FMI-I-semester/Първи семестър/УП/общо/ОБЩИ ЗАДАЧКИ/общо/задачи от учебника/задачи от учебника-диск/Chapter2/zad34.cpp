#include <iostream.h>
#include <math.h>

int main()
{ 
    // първи момент
    unsigned int dayFirst;
    unsigned int hourFirst;
    unsigned int minFirst;

    // втори момент
    unsigned int daySecond;
    unsigned int hourSecond;
    unsigned int minSecond;
    do
    { 
        cout << "Първи ден: ";
        cin >> dayFirst;
        cout << "\n Час: ";
        cin >> hourFirst;
        cout << "\n Минути: ";
        cin >> minFirst;
    } while (dayFirst > 31 || hourFirst > 24 || minFirst > 59);

    do
    {
        cout << "Втори ден: ";
        cin >> daySecond;
        cout << "\n Час: ";
        cin >> hourSecond;
        cout << "\n Минути: ";
        cin >> minSecond;
    } while (daySecond > 31 || hourSecond > 24 || minSecond > 59);

    // Преобразуване на първия и втория момент в минути
    unsigned int firstMin = dayFirst * 24 * 60 + hourFirst * 60 + minFirst;
    unsigned int secondMin = daySecond * 24 * 60 + hourSecond * 60 + minSecond;

    // Изчисляване на разликата между двата момента
    unsigned int minutesDiff = abs((int)(firstMin - secondMin));

    // Преобразуване на разликата в часове и минути
    unsigned int hoursInPeriod = minutesDiff / 60;
    unsigned int minutesInPeriod = minutesDiff % 60;
    cout << "Разликата между двата момента е "
         << hoursInPeriod << " час/а  и " << minutesInPeriod
         << " минути.\n";
    return 0;
}
