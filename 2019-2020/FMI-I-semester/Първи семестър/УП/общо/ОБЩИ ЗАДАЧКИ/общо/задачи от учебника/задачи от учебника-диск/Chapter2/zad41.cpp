#include <iostream.h>

int main()
{ 
    int start,      					// начало на редицата
        end;        					// край на редицата
    do
    { 
        cout << "start= ";
        cin >> start;
        cout << "end= ";
        cin >> end;
    } while (start >= end);

    int step;                           // стъпка
    do
    {
        cout << "step= ";
        cin >> step;
    } while (step < 1);

    // помощна променлива, в която се натрупва сумата
    int sum = 0;
    for(int i = start; i <= end; i += step)
    {
        sum = sum + i;                  // натрупване на сумата
    }
    cout << "Сумата на числата от " << start << " до "
         << end << " със стъпка " << step << " е " << sum
         << endl;
    return 0;
}
