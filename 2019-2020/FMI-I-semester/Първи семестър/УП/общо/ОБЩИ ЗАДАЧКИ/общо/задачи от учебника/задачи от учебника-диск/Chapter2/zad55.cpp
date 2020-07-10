#include <iostream.h>

int main()
{
    cout << "Въведете стойност на n (n>0): ";
    int n, m; 
    cin >> n;
    m = n;
    while(m%2 == 0)
    {
        m = m/2;
    }
    if(m == 1)
    {
        cout << n << " е степен на 2.\n";
    }
    else 
    {
        cout << n << " не е степен на 2.\n";
    }
    return 0;
}
