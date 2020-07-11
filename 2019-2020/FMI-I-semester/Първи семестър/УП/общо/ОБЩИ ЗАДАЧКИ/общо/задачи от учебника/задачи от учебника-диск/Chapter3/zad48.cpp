#include <iostream.h>
#include <iomanip.h>
const int MAX_SIZE = 20;

int main()
{ 
    cout << "Въведете стойност на n в интервала "
            "[1, " << MAX_SIZE << "]: ";
    int n;
    cin >> n;
    int a[MAX_SIZE][MAX_SIZE];

    // въвеждане на матрицата A
    int i, j;
    cout << "Въведете " << n << " реда с по " 
         << n << " цели числа.\n";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // извеждане на матрицата
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }

    // намиране на минималния елемент на ред 0
    // на двумерния масив a в променливата max
    int max = a[0][0];
    for(j = 1; j < n; j++)
    {
        if(a[0][j] < max) 
        {
            max = a[0][j];
        }
    }

    // намиране на максмалния елемент от минималните
    // елементи на матрицата в променливата max
    for(i = 1; i < n; i++)
    {   // намиране на минималния елемент
        // на ред i (в променливата min)
        int min = a[i][0];
        for(j = 1; j < n; j++)
        {
            if(a[i][j] < min)
            {
                min = a[i][j];
            }
        }
        if (min > max)
        {
            max = min;
        }
    }
    cout << "Максимумът от минимумите на редовете на А е: "
         << max << endl;
    return 0;
}
