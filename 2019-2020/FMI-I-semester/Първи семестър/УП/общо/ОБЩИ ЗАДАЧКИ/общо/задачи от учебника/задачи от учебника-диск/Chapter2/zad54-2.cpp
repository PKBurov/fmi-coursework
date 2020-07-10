#include <iostream.h>

int main()
{
    int a, b;

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
    while(a != b)
    {
        if(a > b)
            a = a-b; 
        else 
            b = b-a;
    }
    cout << a << endl;
    return 0;
}
