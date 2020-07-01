#include <iostream.h>
#include <math.h>

int main()
{
    cout << "Въведете реално число: ";
    double x, f;
    cin >> x;

    if(x < -sqrt(5))
    {
        f = x * x - 5;
    }
    else if(x < -1)
    {
        f = 5 - x * x;
    }
    else if (x < 2)
    {
        f = 1 - 2 * x + x * x;
    }
    else if (x < sqrt(5))
    {
        f = 5 - x * x;
    }
    else if (x < 3)
    {
        f = x * x - 5;
    }
    else 
    {
        f = 1 - 2 * x + x*x;
    }

    cout << "f(" << x << ")= " << f << endl;
    return 0;
}
