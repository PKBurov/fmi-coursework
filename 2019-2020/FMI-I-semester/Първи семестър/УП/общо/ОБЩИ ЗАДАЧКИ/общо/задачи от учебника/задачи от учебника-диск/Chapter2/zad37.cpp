#include <iostream.h>

int main() 
{
    double x, y;
    cout << "Въведете стойност на x: "; 
    cin >> x;

    y = 11;
    for(int i = 10; i >= 1; i = i-1)
    {
        y = y*x + i;
    }
    cout << "y= " << y << endl;
    return 0;
}
