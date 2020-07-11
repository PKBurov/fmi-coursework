#include <iostream.h>
#include <math.h>
#include <iomanip.h>
const int MAX_SIZE = 10;

int main()
{
    cout << "Въведете стойност на n от интервала "
            "[2, " << MAX_SIZE << "]: ";
    int n;
    cin >> n;
    double a[MAX_SIZE][MAX_SIZE];

    // Въвеждане на матрицата A
    int i, j;
    cout << "Въведете " << n << " реда с по " 
         << n << " реални числа.\n";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // Извеждане на матрицата
    cout << setiosflags(ios::fixed);
    cout << setprecision(4);
    for(i = 0; i < n; i++)
    { 
        for(j = 0; j < n; j++)
        {
            cout << setw(8) << a[i][j];
        }
        cout << endl;
    }

    // проверка дали матрицата A е ортонормирана
    cout << "Точност eps  в интервала (0, 0.1]: ";
    double eps;
    cin >> eps;
    bool flag = true;

    for(i = 0; i < n && flag; i++)
    {
        for(j = 0; j < n && flag; j++)
        {
            double s = 0;
            for(int k = 0; k < n; k++)
            {
                s = s + a[i][k]*a[j][k];
            }
            if(i == j && fabs(s-1) > eps || i != j && fabs(s) > eps)
            {
                flag = false;
            }
        }
    }

    if(flag) 
    {
        cout << "Матрицата е ортонормирана.\n";
    }
    else 
    {
        cout << "Матрицата не е ортонормирана.\n";
    }
    return 0;
}
