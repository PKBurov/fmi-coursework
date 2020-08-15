#include <iostream.h>
#include <math.h>
#include <iomanip.h>

double Newton(double x, double y, double eps)
{
    double z = 0.5*(x/y + y);
    if(fabs(z-y) < eps) 
    {
        return z;
    }
    return Newton(x, z, eps);
}

double Newton(double x, double eps)
{
    return Newton(x, 1, eps);
}

int main()
{ 
    double x;
    do
    { 
        cout << "x= "; cin >> x;
    }while (x < 0);

    double eps;
    do
    {
        cout << "eps= "; cin >> eps;
    }while (eps <= 0);

    cout << setprecision(8) << setiosflags(ios::fixed);
    cout << Newton(x, eps) << endl;
    cout << sqrt(x) << endl;
    return 0;
}

