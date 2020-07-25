#include <iostream.h>

void func(int a, int b, int c)
{
    cout << "func: a = " << a << endl;
    cout << "func: b = " << b << endl;
    cout << "func: c = " << c << endl;
    return;
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    func(a, b, c);
    cout << "main: a = " << a << endl;
    cout << "main: b = " << b << endl;
    cout << "main: c = " << c << endl;
    return 0;
}
