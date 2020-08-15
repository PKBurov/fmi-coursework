#include <iostream.h>

double func(double x, double y, int i)
{
    if(i > 11) 
        return y;
    return func(x, y*x+i, i+1);
}

double f(double x)
{
    return func(x, 1, 2);
}

int main()
{
    double x;
    cout << "Въведете стойност за x: "; cin >> x;
    cout << f(x) << endl;
    return 0;
}
