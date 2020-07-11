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

    int A[MAX_SIZE1][MAX_SIZE2],
        B[MAX_SIZE1][MAX_SIZE2],
        C[MAX_SIZE1][MAX_SIZE2];
    int i, j;

    // въвеждане на елементите на матрицата A
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        { 
            cout << "A[" << i << "][" << j << "]= ";
            cin >> A[i][j];
        }
    }

    // въвеждане на елементите на матрицата B
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        { 
            cout << "B[" << i << "][" << j << "]= ";
            cin >> B[i][j];
        }
    }

    // намиране на сумата на двете матрици
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // извеждане на сумата на матриците
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cout << setw(5) << C[i][j];
        }
        cout << endl;
    }
    return 0;
}
