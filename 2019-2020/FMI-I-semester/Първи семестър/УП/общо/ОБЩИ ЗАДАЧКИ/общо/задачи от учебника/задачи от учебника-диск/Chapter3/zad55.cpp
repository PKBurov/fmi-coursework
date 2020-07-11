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

    // Въвеждане на таблицата от думи A
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

    // Извеждане на таблицата
    for(i = 0; i < n; i++)
    { 
        for(j = 0; j < n; j++)
        {
            cout << setw(MAX_SIZE2) << a[i][j];
        }
        cout << endl;
    }

    char s1[MAX_SIZE1 * (MAX_SIZE2-1)+1] = "",
         s2[MAX_SIZE1 * (MAX_SIZE2-1)+1] = "";
    for(i = 0; i < n; i++)
    {
        strcat(s1, a[i][i]);
        strcat(s2, a[n-i-1][i]);
    }

    if(!strcmp(s1, s2))
    {
        cout << "Изреченията съвпадат.\n";
    }
    else
    {
        cout << "Изреченията не съвпадат.\n";
    }
    return 0;
}
