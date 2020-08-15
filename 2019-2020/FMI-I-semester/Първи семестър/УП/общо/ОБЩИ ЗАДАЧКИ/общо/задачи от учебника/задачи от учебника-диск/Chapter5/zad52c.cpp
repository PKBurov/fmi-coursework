#include <iostream.h>
const int MAX_1 = 10;
const int MAX_2 = 20;

int mr[MAX_1][MAX_2];   // мрежа
int n, m;               // размери на мрежата
int col;                // цвят на началното квадратче

// преброява квадратчетата от областта, 
// в която се съдържа квадратче (x, y)
int broy(int x, int y)
{ 
    if(x < 0 || x > m-1 || y < 0 || y > n-1) 
        return 0;

    if(mr[x][y] != col)
        return 0;

    if(col == 0) 
    {
        mr[x][y] = 1;
    }
    else 
    {
        mr[x][y] = 0;
    }
    return 1 + broy(x-1, y) + broy(x, y+1)
             + broy(x+1, y) + broy(x, y-1);
}

int main()
{ 
    cout << "Създаване на мрежата: \n";
    do
    { 
        cout << "m= ";
        cin >> m;
    } while(m < 1 && m > MAX_1);
    do
    { 
        cout << "n= ";
        cin >> n;
    } while(n < 1 && n > MAX_2);

    int i, j;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> mr[i][j];
        }
    }

    // въвеждане на квадратче
    cout << "x, y: ";
    int x, y; 
    cin >> x >> y;

    //в)
    if(mr[x][y]) 
    {
        col = 0;
    }
    else
    {
        col = 1;
    }
    int br = 0;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(mr[i][j] == col) 
            { 
                br++; 
                cout << "Размерът на " << br 
                     << " - област е равна на: "
                     << broy(i, j) << endl;
            }
        }
    }
    cout << "Броят на областите е " << br << endl;

    return 0;
}
