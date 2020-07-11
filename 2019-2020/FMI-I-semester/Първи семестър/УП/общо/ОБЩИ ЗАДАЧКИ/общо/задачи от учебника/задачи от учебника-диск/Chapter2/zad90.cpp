#include <iostream.h>

int main()
{
    int n, m;

    do
    {
        cout << "Въведете стойности на m и n (0 < m < n): ";
        cin >> m >> n;
    } while(m <= 0 || m >= n);

    int k;
    do
    {
        cout << "Въведете стойност на k (k > 0): ";
        cin >> k;
    } while(k <= 0);

    for(int i = m; i <= n; i++)
    {
        // намиране на броя на цифрите на i
        int len = 0, a = i;
        while(a != 0)
        {
            len++;
            a = a/10;
        }
        // ако k > len числото няма k-та цифра
        if(k <= len)
        {
            int newnumb;
            int p = 1;
            for(int j = 1; j <= k-1; j++)
            {
                p = p*10;
            }
            newnumb = i/(p*10)*p + i%p;
            if(newnumb != 0 && i % newnumb == 0)
            {
                cout << i << " ";
            }
        }
    }
    cout << endl;
    return 0;
}
