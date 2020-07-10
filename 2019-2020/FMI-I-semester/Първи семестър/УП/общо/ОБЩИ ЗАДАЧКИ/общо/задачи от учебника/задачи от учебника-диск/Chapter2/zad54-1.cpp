#include <iostream.h>

int main()
{
    int a, b, tmp;

    do
    {
        cout << "Въведете положително цяло число a: ";
        cin >> a;
    } while(a <= 0);
    do
    {
        cout << "Въведете положително цяло число b: ";
        cin >> b;
    } while(b <= 0);

    cout << "NOD(" << a << ", " << b << ")= ";
    while(b)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    cout << a << endl;
    return 0;
}
