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

    // проверка дали съществуват два стълба, които си приличат
    bool flag = false;
    int p, q;
    for(p = 0; p < n-1 && !flag; p++)
    {
        for(q = p+1; q < n && !flag; q++)
        { 
            // проверка дали p-ти стълб прилича на q-ти стълб
            // проверка дали всеки елемент на p-ти стълб
            // принадлежи на q-ти стълб на A
            flag = true;
            i = 0; 
            int j;
            while(i < n && flag)
            {
                j = -1;
                do
                {
                    j++;
                }while(a[j][q] != a[i][p] && j < n-1);

                if(a[j][q] != a[i][p])
                {
                    flag = false;
                }
                i++;
            }
            if(flag)
            {   // проверка дали всеки елемент на q-ти стълб
                // принадлежи на p-ти стълб на A
                j = 0;
                while(j < n && flag)
                {
                    int i = -1;
                    do
                    {
                        i++;
                    }
                    while(a[i][p] != a[j][q] && i < n-1);

                    if (a[i][p] != a[j][q]) 
                    {
                        flag = false;
                    }
                    j++;
                }
            }
        }
    }
    if(flag)
    {
        cout << "Съществуват 2 стълба, които си приличат.\n";
    }
    else
    {
        cout << "Не съществуват 2 стълба, които си приличат.\n";
    }

    return 0;
}
