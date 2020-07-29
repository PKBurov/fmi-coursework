#include <iostream.h>

double funcMax(double (*f[])(double), int n, double x)
{
    double maxValue = f[0](x);
    int i;
    for(i = 1; i < n; i++)
    {
        if(maxValue < f[i](x))
        {
            maxValue = f[i](x);
        }
    }
    return maxValue;
}

double linear(double x)
{ 
    return x;
}

double quadratic(double x)
{ 
    return x*x;
}

int main()
{ 
    double (*fList[])(double) = {linear, quadratic};
    cout << funcMax(fList, 2, 0.5) << endl; // 0.5 = linear(0.5)
    cout << funcMax(fList, 2, 2) << endl;    // 4 = quadratic(2)
    return 0;
}
