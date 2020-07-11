#include <iostream.h>

int main()
{
    int n = 1;
    bool flag = true;

    while (n <= 40 && flag)
    {
        int a = 0, b = 1;
        int sum = 0;
        for(int i = 1; i <= n+2; i++)
        { 
            int c = a;
            a = a+b;
            b = c;
            if(i <= n)
            {
                sum = sum + a;
            }
        }
        if(sum != a-1)
        {
            flag = false;
        }
        n = n+1;
    }
    if(flag)
    {
        cout << "Релацията е изпълнена за всяко n "
                "от [1,40]! \n";
    }
    else 
    {
        cout << "Релацията не е изпълнена! \n";
    }
    return 0;
}

