#include <iostream.h>
#include <iomanip.h>

const int MAX_SIZE = 20;

void spiralWalk(int arr[][MAX_SIZE], int n, int m)
{
    int hor = 0, vert = 0, i;
    while(hor < n/2 && vert < m/2)
    {
        for(i = vert; i < m-vert; i++)
            cout << arr[hor][i] << " ";

        for(i = hor+1; i < n-hor; i++)
            cout << arr[i][m-vert-1] << " ";

        for(i = m-vert-2; i >= vert; i--)
            cout << arr[n-hor-1][i] << " ";

        for(i = n-hor-2; i > hor; i--)
            cout << arr[i][vert] << " ";

        ++hor;
        ++vert;
    }

    if(n <= m && n%2)
    {
        for(i = vert; i < m-vert; i++)
        {
            cout << arr[hor][i] << " ";
        }
    }
    else if(m < n && m%2)
    {
        for(i = hor; i < n-hor; i++)
        {
            cout << arr[i][vert] << " ";
        }
    }
}

void print(int arr[][MAX_SIZE], int n, int m)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cout << setw(5) << arr[i][j];
        }
        cout << endl;
    }
}

int main()
{ 
    int arr[MAX_SIZE][MAX_SIZE];
    int n, m, i, j;

    cout << "n: ";
    cin >> n;

    cout << "m: ";
    cin >> m;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        { 
            cout << "a[" << i << "][" << j << "]= ";
            cin >> arr[i][j];
        }
    }

    print(arr, n, m);
    spiralWalk(arr, n, m);
    cout << endl;
    return 0;
}
