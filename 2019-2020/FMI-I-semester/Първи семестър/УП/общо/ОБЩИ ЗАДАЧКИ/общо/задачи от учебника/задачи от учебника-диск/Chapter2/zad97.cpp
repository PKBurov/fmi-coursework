#include <iostream.h>

int main()
{
    cout << "Въведете стойност на a (a>0): ";
    int a;
    cin >> a;

    cout << "Въведете стойност на b (b>a): ";
    int b;
    cin >> b;

    bool flag = false;
    for(int n = a; n <= b && !flag; n++)
    {
        for(int m = a; m <= b && !flag; m++)
        {
            if(n != m && 3*n + 7*m - 5*(n%m) == 3*m + 7*n - 5*(m%n))
            {
                flag = true;
            }
        }
    }
    if(flag)
    {
        cout << "Съществува двойка от естествени числа,"
             << " за която е в сила свойството.\n";
    }
    else
    {
        cout << "Не съществува двойка от естествени числа, "
             << " за която е в сила свойството.\n";
    }
    return 0;
}
