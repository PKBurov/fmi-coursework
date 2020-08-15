#include <iostream.h>

int gcd(int m, int n)
{
    if(n == 0) return m;
    if(m == 0) return n;
    if(m == n) return m;
    if(m > n) return gcd(m-n, n);
    return gcd(m, n-m);
}

int main()
{ 
    int m, n;
    do
    { 
        cout << "m, n= ";
        cin >> m >> n;
    } while (m < 0 || n < 0 || n == 0 && m == 0);

    cout << gcd(m, n) << endl;
    return 0;
}
