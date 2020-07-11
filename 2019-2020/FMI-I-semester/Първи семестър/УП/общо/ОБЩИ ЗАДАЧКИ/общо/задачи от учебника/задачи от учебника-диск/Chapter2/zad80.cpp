#include <iostream.h>

int main()
{
    int n; 
    do
    {
        cout << "Въведете стойност за n (n>=1): ";
        cin >> n;
    } while(n < 1);

    int k;
    for(k = 0; k <= n; k++)
    {
        int numer = 1;
        int denom = 1;
        for(int i = 0; i < k; i++)
        {
            numer = numer*(n-i);
            denom = denom*(i+1);
        }
        cout << numer/denom << " ";
    }
    cout << endl;
    return 0;
}
