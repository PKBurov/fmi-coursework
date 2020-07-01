#include <iostream.h>

int main()
{ 
    int m, n;
    do
    { 
        cout << "Въведете цели стойности за m и n (m < n): ";
        cin >> m >> n;
    } while(m >= n);

    if(n < 100 || m > 999)
    {
        cout << "Интервалът [" << m << ", " << n 
             << "] не съдържа трицифрени числа\n"; 
    }
    else
    {
        int a, b;

        if (m < 100)
            a = 100; 
        else
            a = m;

        if (n > 999)
            b = 999;
        else 
            b = n;

        for(int i = a; i <= b; i++)
        {
            if(i%(i/100*10+i%10) == 0)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
