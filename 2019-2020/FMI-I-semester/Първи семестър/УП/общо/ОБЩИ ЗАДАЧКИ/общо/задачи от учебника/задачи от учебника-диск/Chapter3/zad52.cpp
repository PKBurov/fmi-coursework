#include <iostream.h>
#include <iomanip.h>
#include <string.h>
const int MAX_SIZE1 = 30;
const int MAX_SIZE2 = 10;

int main()
{
    cout << "Въведете стойност на n в интервала "
            "[1, " << MAX_SIZE1 << "]: ";
    int n; 
    cin >> n;
    char a[MAX_SIZE1][MAX_SIZE1][MAX_SIZE2];

    // въвеждане на таблицата от думи A
    int i, j;
    cout << "Въведете " << n << " реда с по " << n
         << " символни низа с максимална дължина "
         << MAX_SIZE2 - 1 << "!\n";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // извеждане на таблицата
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout << setw(MAX_SIZE2) << a[i][j];
        }
        cout << endl;
    }

    for(i = 0; i < n; i++)
    {
        // сортиране във възходящ ред на i-тия ред на таблицата
        for(int p = 0; p < n-1; p++)
        {
            int k = p; 
            char min[MAX_SIZE2]; strcpy(min, a[i][p]);
            for(j = p+1; j < n; j++)
            {
                if(strcmp(a[i][j], min) < 0)
                { 
                    strcpy(min, a[i][j]);
                    k = j;
                }
            }
            strcpy(a[i][k], a[i][p]);
            strcpy(a[i][p], min);
        }
    }

    // извеждане на сортираната по редове таблица от низове
    cout << "\n\n"
         << "Сортираната по редове таблица\n";
    for(i = 0; i < n; i++)
    { 
        for(j = 0; j < n; j++)
        {
            cout << setw(MAX_SIZE2) << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
