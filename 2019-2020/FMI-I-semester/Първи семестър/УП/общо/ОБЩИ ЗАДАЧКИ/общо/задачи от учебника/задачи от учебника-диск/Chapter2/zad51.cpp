#include <iostream.h>

int main()
{
    int x = 0, p = 1;
    unsigned y = 0;
    cout << "Въведете цяло число: ";
    cin >> x;
    cout << "Въведете неотрицателно цяло число: ";
    cin >> y;

    while (y > 0)
    {
        if(y % 2 == 0)
        {
            x *= x;
            y /= 2;
        }
        else
        {
            y--;
            p *= x;
        }
    }
    cout << "Степента е = " << p << "\n";
    return 0;
}
