#include <iostream.h>

void func()
{
    return;
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    func();
    cout << "main: a = " << a << endl;
    cout << "main: b = " << b << endl;
    cout << "main: c = " << c << endl;
    return 0;
}
