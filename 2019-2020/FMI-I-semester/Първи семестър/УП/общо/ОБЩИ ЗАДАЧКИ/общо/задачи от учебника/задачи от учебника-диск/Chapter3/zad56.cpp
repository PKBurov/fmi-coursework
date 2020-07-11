#include <iostream.h>
#include <string.h>
#include <iomanip.h>
const int MAX_SIZE1 = 20;
const int MAX_SIZE2 = 10;

int main()
{
    char a[MAX_SIZE1][MAX_SIZE1][MAX_SIZE2];
    int n, i, j;
    // въвеждане на квадратната матрица от низове
    cout << "n: ";
    cin >> n;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }

    // извеждане на екрана на квадратната матрица от низове
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout << setw(MAX_SIZE2) << a[i][j];
        }
        cout << endl;
    }

    // обхождане по спирала на квадратната матрица от
    // низове, започвайки от горния ляв ъгъл по посока
    // на часовниковата стрелка
    char s[MAX_SIZE1* MAX_SIZE1*( MAX_SIZE2-1)+1] = "";
    int hor = 0, vert = 0;
    while(hor < n/2 && vert < n/2)
    {
        for(i = vert; i < n-vert; i++)
        {
            strcat(s, a[hor][i]);
        }
        for(i = hor+1; i < n-hor; i++)
        {
            strcat(s, a[i][n-vert-1]);
        }
        for(i = n-vert-2; i >= vert; i--)
        {
            strcat(s, a[n-hor-1][i]);
        }
        for(i = n-hor-2; i > hor; i--)
        {
            strcat(s, a[i][vert]);
        }
        hor++;
        vert++;
    }
    if(n%2)
    {
        for(i = vert; i < n-vert; i++)
        {
            strcat(s, a[hor][i]);
        }
    }
    else
    {
        for(i = hor; i < n-hor; i++)
        {
            strcat(s, a[i][vert]);
        }
    }
    cout << s << endl;
    return 0;
}
