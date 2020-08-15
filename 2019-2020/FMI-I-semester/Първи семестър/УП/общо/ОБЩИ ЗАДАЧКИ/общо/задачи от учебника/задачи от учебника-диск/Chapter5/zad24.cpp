#include <iostream.h>

int sum(int a, int b, int (*f)(int), bool (*pred)(int))
{
    if(a > b)
    {
        return 0;
    }
    return (pred(a)? f(a) : 0) + sum(a+1, b, f, pred);
}

int id(int x)
{
    return x;
}

bool all(int)
{
    return true;
}

bool st3(int x)
{
    return x%3 == 0;
}

int main()
{ 
    cout << sum(1, 3, id, all) << endl; 	// 1 + 2 + 3
    cout << sum(1, 10, id, st3) << endl;	// 3 + 6 + 9
    return 0;
}
