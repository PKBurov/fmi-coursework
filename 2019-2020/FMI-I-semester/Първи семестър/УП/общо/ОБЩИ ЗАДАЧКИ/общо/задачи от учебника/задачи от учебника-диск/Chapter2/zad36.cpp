#include <iostream.h>

int main() 
{
    double x, y;
    cout << "Въведете стойност на x: "; cin >> x;
    y = 1;
    for(int i = 2; i <= 11; i = i+1)
    {
        y = y*x + i;
    }
    cout << "y= " << y << endl;
    return 0;
}
