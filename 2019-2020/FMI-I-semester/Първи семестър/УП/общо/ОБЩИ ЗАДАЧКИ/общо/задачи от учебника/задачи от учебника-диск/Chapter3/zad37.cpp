#include <iostream.h>
#include <iomanip.h>
const int MAX_SIZE1 = 10;
const int MAX_SIZE2 = 20;

int main()
{
    cout << "Въведете стойност на n от интервала "
            "[1, " << MAX_SIZE1 << "]: ";
    int n;
    cin >> n;
    cout << "Въведете стойност на m от интервала "
            "[1, " << MAX_SIZE2 << "]: ";

    int m;
    cin >> m;
    double a[MAX_SIZE1][MAX_SIZE2];

    // въвеждане на матрицата A
    int i, j;
    cout << "Въведете " << n << " реда с по " 
         << m << " реални числа!\n";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    // изтриване на k-тия стълб на А
    cout << "Въведете стойност на k от интервала [0, " 
         << m-1 << "]: ";

    int k;
    cin >> k;
    if(k != m-1) 
    {
        for(j = k+1; j < m; j++)
        {
            for(i = 0; i < n; i++)
            {
                a[i][j-1] = a[i][j];
            }
        }
    }
    m--;

    // извеждане на новата матрица
    cout << setprecision(2) << setiosflags(ios::fixed);
    for(i = 0; i < n; i++)
    { 
        for(j = 0; j < m; j++)
        {
            cout << setw(8) << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
