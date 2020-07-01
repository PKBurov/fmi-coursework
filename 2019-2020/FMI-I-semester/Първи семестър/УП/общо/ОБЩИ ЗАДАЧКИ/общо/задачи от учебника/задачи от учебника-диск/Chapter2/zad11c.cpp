#include <iostream.h>

int main()
{
    double x, y;
    cout << "x= ";
    cin >> x;
    cout << "y= ";
    cin >> y;
    int radius = 1;

    if((x - 1)*(x - 1) + (y - 1)*(y - 1) <= radius*radius)
    {
        cout << "Точката принадлежи на кръга.\n";
    }
    else
    {
        cout << "Точката не принадлежи на кръга.\n";
    }
    return 0;
}
