#include <iostream.h>
#include <iomanip.h>
#include <math.h>

int main()
{
    int x, // входна данна
        h, // стъпка
        a, // начало на интервала
        b; // край на интервала

    do
    {
        cout << "Въведете цяло число x от 1 до 1000:\n";
        cin >> x;
    } while (x < 1 || x > 1000);
    cout << "*******************************************"
            "**********************\n";
    cout << setw(5) << "x" << setw(15) << "ln(x)" << setw(15) 
         << "lg(x)" << setw(15) << "x^1/3" << setw(15) 
         << "x^1/2\n";
    cout << "*******************************************"
            "**********************\n";
    cout << setiosflags(ios::fixed) << setprecision(5);

    if(x <= 10)
    { 
        a = 1;
        b = 10;
        h = 1;
    }
    else
    {
        if(x <= 100)
        {
            a = 20; 
            b = 100; 
            h = 10;
        }
        else
        { 
            a = 200; 
            b = 1000; 
            h = 100;
        }
    }
    for(int i = a; i <= b; i = i+h)
    {
        cout << setw(5)  << i << setw(15) << log(i)
             << setw(15) << log10(i)
             << setw(15) << pow(i, 1./3)
             << setw(15) << sqrt(i) << endl;
    }
    return 0;
}
