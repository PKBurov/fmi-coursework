#include <iostream.h>

int main()
{
    int n; 
    int fib;

    do
    { 
        cout << "Въведете цяло неотрицателно число: ";
        cin >> n;
    } while(n < 0);

    if(n == 0)
    {
        fib = 0;
    }
    else if(n == 1)
    {
        fib = 1;
    }
    else
    {
        int a = 0, b = 1;
        for(int i = 1; i <= n; i++)
        { 
            int c = a;
            a = a+b;
            b = c;
        }
        fib = a;
    }
    cout << "fib(" << n << ")= " << fib << endl;
    return 0;
}
