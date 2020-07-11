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
         << n << " цели числа!\n";
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

    // намиране на всички k от 0 до n-1, за които
    // k-тият стълб съвпада с k-тия ред на A
    for(int k = 0; k < n; k++)
    { 
        int i = -1;
        do
        {
            i++;
        }
        while(a[i][k] == a[k][i] && i < n-1);

        if(a[i][k] == a[k][i])
        {
            cout << k << endl;
        }
    }
    return 0;
}
