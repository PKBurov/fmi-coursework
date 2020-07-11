#include <iostream.h>
const int MAX_SIZE = 10;

int main()
{
    cout << "Въведете стойност на размерността "
            "на A в интервала [1, " << MAX_SIZE << "]: ";
    int n;
    cin >> n;
    int a[MAX_SIZE][MAX_SIZE];

    // Въвеждане на матрицата A
    int i, j;
    cout << "Въведете " << n << " реда с по " 
         << n << " цели числа.\n" ;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // намиране на сумата от нечетните числа под
    // главния диагонал на A (без него)
    int sum = 0;
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(a[i][j]%2 == 1) 
            {
                sum = sum + a[i][j];
            }
        }
    }
    cout << "sum: " << sum << endl;
    return 0;
}
