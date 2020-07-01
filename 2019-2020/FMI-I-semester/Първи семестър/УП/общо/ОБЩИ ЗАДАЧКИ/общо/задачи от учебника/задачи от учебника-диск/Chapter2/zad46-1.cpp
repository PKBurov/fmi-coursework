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
        for(int i = 100; i <= 999; i++)
        {
            if(i >= m && i <= n && i % (i/100*10+i%10) == 0)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
