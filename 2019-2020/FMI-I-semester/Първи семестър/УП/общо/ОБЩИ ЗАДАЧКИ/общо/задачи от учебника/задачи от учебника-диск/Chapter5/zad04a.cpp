#include <iostream.h>
#include <iomanip.h>
#include <math.h>

double f(double x, int y)
{
    if(y == 0) 
        return 1.0;
    return x*f(x, y-1);
}

int main()
{
    cout << "x= ";
    double x; 
    cin >> x;
    int y;
    do
    { 
        cout << "y= ";
        cin >> y;
    } while (y < 0);

    cout << setprecision(10) << setiosflags(ios::fixed);
    cout << f(x, y) << endl;
    cout << pow(x, y) << endl;
    return 0;
}
