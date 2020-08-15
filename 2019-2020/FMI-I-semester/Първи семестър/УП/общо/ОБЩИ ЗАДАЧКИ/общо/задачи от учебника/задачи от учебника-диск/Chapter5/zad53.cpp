#include <iostream.h>
#include <iomanip.h>

const int MAX = 100;
int mat[MAX][MAX], n, m;

void init()
{ 
    cout << "n= ";
    cin >> n;
    cout << "m= ";
    cin >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        { 
            cout << "mat[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    }
}

void print()	
{
    for(int i = 0; i < n; i++)
    { 
        for(int j = 0; j < m; j++)
        {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void mark(int i, int j, int num)
{
    if(i < 0 || j < 0 || i >= n || j >= m) 
        return;
    if(mat[i][j] != 1) 
        return;
    mat[i][j] = num;
    mark(i+1, j, num);
    mark(i-1, j, num);
    mark(i, j+1, num);
    mark(i, j-1, num);
}

int cnt_connected()
{ 
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == 1)
            {
                cnt++;
                mark(i, j, -cnt);
            }
        }
    }
    return cnt;
}

int main()
{
    init();
    print();
    cout << "Броят на областите в мрежата е " 
         << cnt_connected() << endl;
    return 0;
}
