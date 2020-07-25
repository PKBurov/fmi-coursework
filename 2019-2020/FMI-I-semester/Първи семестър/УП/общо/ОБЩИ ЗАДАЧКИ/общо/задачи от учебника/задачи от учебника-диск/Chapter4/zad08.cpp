#include <iostream.h>

void func(const int x, int &y, int* z)
{
    int a = 3;
    int b = 4;
    a = b + y;
    y = x + a;
    z = &b;
    cout << "func: x =  " << x << endl;
    cout << "func: y =  " << y << endl;
    cout << "func: *z = " << *z << endl;
    cout << "func: a =  " << a << endl;
    cout << "func: b =  " << b << endl;
    return;
}

int main()
{
    int a = 1;
    int b = 2;
    func(b, a, &a);
    cout << "main: a = " << a << endl;
    cout << "main: b = " << b << endl;
    return 0;
}
