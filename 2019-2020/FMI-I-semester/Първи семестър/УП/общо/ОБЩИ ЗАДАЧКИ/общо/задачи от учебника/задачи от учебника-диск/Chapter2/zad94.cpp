#include <iostream.h>

int main()
{
    bool flag = true;
    for(int n = 1; n <= 20 && flag; n++)
    {
        for(int m = 1; m <= 20 && flag; m++)
        {
            int fib1, fib2, fib3, fib4, fib;
            int a = 0, b = 1;
            for(int i = 1; i <= n+m; i++)
            {
                int c = a;
                a = a+b;
                b = c;
                if(i == n)
                {
                    fib1 = b;
                    fib2 = a;
                }
                if(i == m+1)
                {
                    fib3 = b;
                    fib4 = a;
                }
            }
            fib = a;
            if(fib != fib1*fib3 + fib2*fib4)
            {
                flag = false;
            }
        }
    }
    if(flag)
    {
        cout << "Релацията е в сила!\n";
    }
    else
    {
        cout << "Релацията не е в сила!\n";
    }
    return 0;
}
