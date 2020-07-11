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

    // намиране на броя на низовете палиндроми над главния
    // диагонал (без него) на таблицата от думи
    int br = 0;
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {   // проверка дали a[i][j] е палиндром
            int len = strlen(a[i][j]);
            char rev[MAX_SIZE2];
            for(int k = len-1; k >= 0; k--)
            {
                rev[len-k-1] = a[i][j][k];
            }

            rev[len] = '\0';
            if(!strcmp(a[i][j], rev)) 
            {
                br++;
            }
        }
    }

    cout << "Броят на палиндромите над главния диагонал е: "
         << br << endl;
    return 0;
}
