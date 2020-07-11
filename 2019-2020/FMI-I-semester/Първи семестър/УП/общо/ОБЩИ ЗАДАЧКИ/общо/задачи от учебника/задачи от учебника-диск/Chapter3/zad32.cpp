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
    cout << "Въведете " << n << " реда с по " << n 
         << " цели числа.\n" ;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // намиране на сумата от елементите от вторичния
    // главен диагонал на A, които са кратни на n
    int sum = 0;
    for(i = 0; i < n; i++)
    {
        if(a[n-i-1][i] % n == 0)
        {
            sum = sum + a[n-i-1][i];
        }
    }
    cout << "Сумата от елементите е " << sum << endl;
    return 0;
}
