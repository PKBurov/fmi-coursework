#include <iostream.h>
#include <math.h>

double Root_P(double x, int p, double y, double eps)
{ 
    if(x < 0 && p%2 == 0)
    { 
        cout << "Error! \n";
        return -1;
    }

    if(x == 0) return 0;

    double z = 1./p * ((p-1)*y + x/pow(y, p-1));
    if(fabs(z-y) < eps) 
    {
        return z;
    }
    return Root_P(x, p, z, eps);
}

double Root_P(double x, int p, double eps)
{
    return Root_P(x, p, x, eps);
}

