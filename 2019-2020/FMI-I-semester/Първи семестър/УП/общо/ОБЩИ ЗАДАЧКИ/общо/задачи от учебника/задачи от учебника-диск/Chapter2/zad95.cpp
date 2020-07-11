#include <iostream.h>

int main()
{
    bool flag1 = true, flag2 = true;
    int n = 1;
    int a = 0, b = 1;

    while(n <= 40 && flag1 && flag2)
    {
        int c = a;
        a = a+b;
        b = c;
        if(a%2 == 0)
        {
            if(n%3 != 0)
            {
                flag1 = false;
            }
        }
        if(n%3 == 0) 
        {
            if(a%2 != 0)
            {
                flag2 = false;
            }
        }
        n++;
    }

    if(flag1 && flag2)
    {
        cout << "Свойството е в сила.\n";
    }
    else
    {
        cout << "Свойството не е в сила.\n";
    }
    return 0;
}
