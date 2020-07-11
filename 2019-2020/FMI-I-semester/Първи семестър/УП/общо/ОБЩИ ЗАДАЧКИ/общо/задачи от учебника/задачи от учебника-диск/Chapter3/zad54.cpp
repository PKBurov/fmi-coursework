#include <iostream.h>
#include <iomanip.h>
#include <string.h>
const int MAX_SIZE1 = 30;
const int MAX_SIZE2 = 7;

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

    char s[MAX_SIZE2];
    cout << "Въведете търсената дума: "; 
    cin >> s;

    // намиране на броя на срещанията на думата s под вторичния
    // главeн диагонал (без него) на таблицата от думи
    int br = 0;
    for(i = 1; i < n; i++)
    {
        for(j = n-i; j < n; j++)
        {
            if(!strcmp(a[i][j], s)) 
            {
                br++;
            }
        }
    }

    cout << "Броят на срещанията на думата " << s
         << " под вторичния главен диагонал (без него) е: " << br << endl;
    return 0;
}
