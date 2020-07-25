#include <iostream.h>

const int MAX_SIZE = 10000;

void SieveOfEratosthenes(int n, int a[])
{
    int i;
    a[0] = a[1] = 0;
    for(i = 2; i < n; i++)
    {
        a[i] = 1;
    }
    for(i = 2; i < n; i++)
    {
        if(a[i])
        {
            for(int j = i; i*j < n; j++)
            {
                a[i*j] = 0;
            }
        }
    }
}

void WritePrime(int n, int a[])
{
    for(int i = 0; i < n; i++)
    {
        if(a[i])
        {
            cout << i << "  " ;
        }
    }
    cout << endl;
}

int main()
{
    cout << "n от 1 до " << MAX_SIZE << ": ";
    int n; 
    cin >> n;
    int a[MAX_SIZE];
    SieveOfEratosthenes(n, a);
    WritePrime(n, a);
    return 0;
}
