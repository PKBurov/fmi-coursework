#include <iostream.h>

int main()
{
    cout << "Въведете стойност на a(a>0): ";
    int a; 
    cin >> a;

    cout << "Въведете стойност на b(b>a): ";
    int b; 
    cin >> b;

    for(int n = a; n <= b; n++)
    {
        for(int m = a; m <= b; m++)
        {
            if(n != m && 3*n + 7*m - 5*(n%m) == 3*m + 7*n - 5*(m%n))
            {
                cout << "(" << n << ", " << m << ")\n";
            }
        }
    }
    return 0;
}
