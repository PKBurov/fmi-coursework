#include <iostream.h>

int main()
{
    int x = 0,
        y = 0,
        count = 1;
    do
    {
        cout << "x (x>=0) ";
        cin >> x;
    } while(x < 0);
    do
    {
        cout << "y (цифра) ";
        cin >> y;
    } while(y < 0 || y > 9);

    if(x == 0 && y == 0)
    {
        cout << " Поредният номер е " << count << ". \n";
        return 0;
    }

    while(x > 0 && x % 10 != y)
    {
        x /= 10;
        count++;
    }
    if(x == 0)
    {
        cout << "Не се среща!\n";
    }
    else
    {
        cout << "Поредният номер е " << count << ". \n";
    }
    return 0;
}
