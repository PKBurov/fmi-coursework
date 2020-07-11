#include <iostream.h>

int main()
{
    int n; 
    do
    {
        cout << "Въведете положително цяло число: ";
        cin >> n;
    } while(n <= 0);

    // 1 не е съвършено
    // затова проверката за съвършени числа започва от k = 2
    for(int k = 2; k <= n; k++)
    {
        // намиране на сумата от делителите на k
        int s = 1;
        for(int i = 2; i <= k/2; i++)
        {
            if(k % i == 0) 
            {
                s = s + i;
            }
        }
        if (s == k)
        {
            cout << k << " е съвършено.\n";
        }
    }
    return 0;
}
