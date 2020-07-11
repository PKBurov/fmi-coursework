#include <iostream.h>
#include <iomanip.h>
const int MAX_SIZE1 = 20;
const int MAX_SIZE2 = 30;
const int MAX_SIZE3 = 40;

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

    cout << "Въведете стойност на k в интервала "
            "[1, " << MAX_SIZE3 << "]: ";
    int k;
    cin >> k;

    int A[MAX_SIZE1][MAX_SIZE2],
        B[MAX_SIZE2][MAX_SIZE3],
        C[MAX_SIZE1][MAX_SIZE3];

    // въвеждане на елементите на матрицата A
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        { 
            cout << "A[" << i << "][" << j << "]= ";
            cin >> A[i][j];
        }
    }

    // въвеждане на елементите на матрицата B
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < k; j++)
        { 
            cout << "B[" << i << "][" << j << "]= ";
            cin >> B[i][j];
        }
    }

    // намиране на произведението на A и B
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < k; j++)
        {
            C[i][j] = 0;
            for(int l = 0; l < m; l++)
            {
                C[i][j] += A[i][l] * B[l][j];
            }
        }
    }

    // извеждане на произведението
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < k; j++)
        {
            cout << setw(5) << C[i][j];
        }
        cout << endl;
    }
    return 0;
}
