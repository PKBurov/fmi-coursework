#include <iostream.h>

int main()
{
    int m, n;
    do
    {
        cout << "Въведете стойности за m и n, цели и 0<=m<n: ";
        cin >> m >> n;
    } while(m < 0 || m >= n);

    for(int i = m; i <= n; i++)
    {
        int a = i; 
        while(a != 0 && a%10 != 5) 
        {
            a = a/10;
        }
        if(a != 0) 
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
