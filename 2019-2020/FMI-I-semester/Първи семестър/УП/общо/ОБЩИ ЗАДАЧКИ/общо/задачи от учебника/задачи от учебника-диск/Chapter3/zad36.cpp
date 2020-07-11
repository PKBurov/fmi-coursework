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
         << m << " реални числа.\n";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    // изтриване на k-тия ред на А
    cout << "Въведете стойност на k от интервала"
            "[0, " << n-1 << "]: ";
    int k;
    cin >> k;
    if(k != n-1) 
    {
        for(i = k+1; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                a[i-1][j] = a[i][j];
            }
        }
    }
    n--;

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
