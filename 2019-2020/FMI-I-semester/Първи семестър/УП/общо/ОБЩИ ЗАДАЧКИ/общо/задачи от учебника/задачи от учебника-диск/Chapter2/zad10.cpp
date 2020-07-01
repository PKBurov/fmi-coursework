#include <iostream.h>

int main()
{
    double a, b;
    double x;
    cout << "Въведете стойности на a и b: ";
    cin >> a >> b;

    if(a > b)  // границите на интервала са обърнати
    {   // смяна на местата им
        double t = a;
        a = b;
        b = t;
    }

    cout << "x= ";
    cin >> x;
    if (x >= a && x <= b)
    {
        cout << x << " принадлежи на [" << a
             << ", " << b << "]!\n";
    }
    else
    {
        cout << x << " не принадлежи на [" << a 
             << ", " << b << "]!\n";
    }
    return 0;
}
