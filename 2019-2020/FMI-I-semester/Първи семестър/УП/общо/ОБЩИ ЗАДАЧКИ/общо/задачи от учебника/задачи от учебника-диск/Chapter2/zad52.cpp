#include <iostream.h>

int main()
{
    int x = 0,
        y = 2,
        z = 0;
    do
    {
        cout << "Въведете положително цяло число: ";
        cin >> x;
    } while(x <= 0);

    while(y <= x)
    {
        y *= 2;
        z++;
    }
    cout << z << "\n";
    return 0;
}
