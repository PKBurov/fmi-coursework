#include <iostream.h>

int main()
{
    double x, y;
    cout << "x= ";
    cin >> x;
    cout << "y= ";
    cin >> y;

    if(x >= -1 && x <= 1 && y >= -1 && y <= 1)
    {
        cout << "Точката принадлежи на квадрата.\n";
    }
    else
    {
        cout << "Точката не принадлежи на квадрата.\n";
    }
    return 0;
}
