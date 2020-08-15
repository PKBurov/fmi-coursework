#include <iostream.h>

int Ack(int m, int n)
{
    if(m == 0) return n+1;
    if(n == 0) return Ack(m-1, 1);
    return Ack(m-1, Ack(m, n-1));
}

int main()
{
    int m, n;
    do
    {
        cout << "m, n= ";
        cin >> m >> n;
    } while (m < 0 || n < 0);

    cout << "Ack(" << m << ", " << n << ")= " 
         << Ack(m, n) << endl;
    return 0;
}
