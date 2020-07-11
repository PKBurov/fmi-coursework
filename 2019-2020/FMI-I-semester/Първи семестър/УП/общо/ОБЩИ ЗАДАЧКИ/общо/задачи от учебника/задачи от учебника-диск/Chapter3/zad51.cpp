#include <iostream.h>
#include <iomanip.h>
const int MAX_SIZE1 = 50;
const int MAX_SIZE2 = 100;

int main()
{
    cout << "Въведете стойност на n в интервала "
            "[1, " << MAX_SIZE1 << "]: ";
    int n; 
    cin >> n;
    int a[MAX_SIZE1][3];

    // въвеждане на матрицата A
    int i, j;
    cout << "Въведете " << n << " реда с по " 
        << "3 цели числа!\n";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    // извеждане на матрицата
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }

    cout << "Въведете стойност на m в интервала "
            "[1, " << MAX_SIZE1 << "]: ";
    int m;
    cin >> m;
    int b[MAX_SIZE1][3];

    // въвеждане на матрицата B
    cout << "Въведете " << m << " реда с по 3 цели числа.\n";
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cin >> b[i][j];
        }
    }

    // извеждане на матрицата
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cout << setw(5) << b[i][j];
        }
        cout << endl;
    }

    // намиране на сумата на матриците
    int c[MAX_SIZE2][3];
    i = 0; j = 0;
    int k = -1;
    while(i < n && j < m)
    {
        if(a[i][0] < b[j][0] || a[i][0] == b[j][0] && a[i][1] < b[j][1])
        { 
            k++;
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
        }
        else if(a[i][0] > b[j][0] || a[i][0] == b[j][0] && a[i][1] > b[j][1])
        { 
            k++;
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++;
        }
        else
        { 
            if(a[i][2] + b[j][2] != 0)
            {
                k++;
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2] + b[j][2];
            }
            i++; j++;
        }
    }

    while(j < m)
    {
        k++;
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++;
    }

    while(i < n)
    {
        k++;
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++;
    }
    k++;

    // извеждане на матрицата - сума
    cout << "Сума на матриците\n";
    for(i = 0; i < k; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cout << setw(5) << c[i][j];
        }
        cout << endl;
    }
    return 0;
}
