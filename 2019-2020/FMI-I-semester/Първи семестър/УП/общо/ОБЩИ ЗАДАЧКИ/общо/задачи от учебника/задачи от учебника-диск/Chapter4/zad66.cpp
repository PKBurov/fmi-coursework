#include <iostream.h>

int sum(int a, int b, int (*f)(int), int (*next)(int))
{ 
    int s = 0;
    for(int i = a; i <= b; i = next(i))
    {
        s = s + f(i);
    }
    return s;
}

int prod(int a, int b, int (*f)(int),  int (*next)(int))
{
    int p = 1;
    for(int i = a; i <= b; i = next(i))
    {
        p = p * (*f)(i);				// или p = p * f(i);
    }
    return p;
}

int ident(int j)
{
    return j;
}

int next1(int i)
{
    return i+1;
}

int f(int i)
{
    return prod(1, i, ident, next1);
}

int s1(int n)
{
    return sum(1, n, f, next1);
}

int s2(int n)
{
    return prod(1, n, s1, next1);
}

int main()
{
    cout << "n= "; int n;
    cin >> n;
    cout << s1(n) << endl;
    cout << s2(n) << endl;
    return 0;
}
