#include <iostream.h>

const int a = 7;

void func(const int& x, const int* y = &a, int z = 6)
{
    int a = 4;
    int b = 5;
    z = x + *y + a + b;
    cout << "func: x = " << x << endl;
    cout << "func: *y = " << *y << endl;
    cout << "func: z = " << z << endl;
    cout << "func: a = " << a << endl;
    cout << "func: b = " << b << endl;
    return;
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    func(a, &b, c);
    func(b, &c);
    func(c);
    cout << "main: a = " << a << endl;
    cout << "main: b = " << b << endl;
    cout << "main: c = " << c << endl;
    return 0;
}
