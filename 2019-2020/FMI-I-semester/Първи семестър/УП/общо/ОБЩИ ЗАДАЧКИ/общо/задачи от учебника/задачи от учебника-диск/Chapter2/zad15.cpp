#include <iostream.h>
#include <math.h>

int main()
{
    double a, x;
    cout << "Въведете стойност на a: ";
    cin >> a;

    if(a > 0)
    {
        x = -sqrt(fabs(a-1))/(5*pow(a, 1./3));
    }
    else
    {
        x = log(a*a+5)/(a-1);
    }

    cout << "x= " << x << endl;
    return 0;
}
