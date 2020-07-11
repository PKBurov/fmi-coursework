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

    // проверка дали съществуват два реда, които си приличат
    bool flag = false;
    int p, q;
    for(p = 0; p < n-1 && !flag; p++)
    {
        for(q = p+1; q < n && !flag; q++)
        {   
            int j;
            // проверка дали p-ти ред прилича на q-ти ред
            // проверка дали всеки елемент на p-ти ред
            // принадлежи на q-ти ред на A
            flag = true;
            i = 0; 
            while (i < n && flag)
            { 
                j = -1;
                do
                {
                    j++;
                }while(a[q][j] != a[p][i] && j < n-1);

                if(a[q][j] != a[p][i])
                {
                    flag = false;
                }
                i++;
            }
            if(flag)
            {   // проверка дали всеки елемент на q-ти ред
                // принадлежи на p-ти ред на A
                j = 0;
                while(j < n && flag)
                { 
                    int i = -1;
                    do
                    {
                        i++;
                    }while(a[p][i] != a[q][j] && i < n-1);

                    if(a[p][i] != a[q][j])
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
        cout << "Съществуват 2 реда, които си приличат.\n";
    }
    else
    {
        cout << "Не съществуват 2 реда, които си приличат.\n";
    }
    return 0;
}
