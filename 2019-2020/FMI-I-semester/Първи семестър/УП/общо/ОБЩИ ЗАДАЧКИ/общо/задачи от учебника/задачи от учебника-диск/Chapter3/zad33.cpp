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

    // Намиране на произведението от елементите под
    // вторичния главен диагонал на A.
    int prod = 1;
    for(i = 1; i < n; i++)
    {
        for(j = n-i; j < n; j++)
        {
            prod = prod * a[i][j];
        }
    }
    cout << "Произведението е : " << prod << endl;
    return 0;
}
