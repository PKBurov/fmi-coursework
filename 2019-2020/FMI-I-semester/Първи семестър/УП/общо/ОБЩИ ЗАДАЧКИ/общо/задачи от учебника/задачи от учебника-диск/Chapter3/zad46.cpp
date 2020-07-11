#include <iostream.h>
#include <iomanip.h>
const int MAX_SIZE1 = 20;
const int MAX_SIZE2 = 30;

int main()
{
    cout << "Въведете стойност на n в интервала "
            "[1, " << MAX_SIZE1 << "]: ";
    int n;
    cin >> n;

    cout << "Въведете стойност на m в интервала "
            "[1, " << MAX_SIZE2 << "]: ";
    int m;
    cin >> m;
    int a[MAX_SIZE1][MAX_SIZE2];

    // въвеждане на матрицата A
    int i, j;
    cout << "Въведете " << n << " реда с по "
         << m << " цели числа.\n";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    // извеждане на матрицата
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }

    // намиране на минималните елементи на всеки ред на A
    int min[MAX_SIZE1];
    for(i = 0; i < n; i++)
    {
        min[i] = a[i][0];
        for(j = 1; j < m; j++)
        {
            if(a[i][j] < min[i]) 
            {
                min[i] = a[i][j];
            }
        }
    }

    // намиране на максималните елементи на всеки стълб на A
    int max[MAX_SIZE2];
    for(j = 0; j < m; j++)
    { 
        max[j] = a[0][j];
        for(i = 1; i < n; i++)
        {
            if(a[i][j] > max[j])
            {
                max[j] = a[i][j];
            }
        }
    }

    // проверка дали съществува седлова точка на матрицата А
    bool flag = false;
    for(i = 0; i < n && !flag; i++)
    {
        for(j = 0; j < m && !flag; j++)
        {
            if(a[i][j] == min[i] && a[i][j] == max[j])
            {
                flag = true;
            }
        }
    }
    if(flag) 
    {
        cout << "Съществува седлова точка.\n";
    }
    else
    {
        cout << "Не съществува седлова точка.\n";
    }

    return 0;
}
