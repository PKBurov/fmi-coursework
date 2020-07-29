#include <iostream.h>
#include <iomanip.h>

const int MAX_SIZE = 20;

void spiralWalk(int arr[][MAX_SIZE], int n, int (*f)(int), int (*g)(int))
{
    int (*p)(int);
    int hor = 0, vert = 0, i;
    while(hor < n/2 && vert < n/2)
    {
        if(hor%2 == 0) 
            p = f; 
        else 
            p = g;

        for(i = vert; i < n-vert; i++)
            cout << p(arr[hor][i]) << " ";

        for(i = hor+1; i < n-hor; i++)
            cout << p(arr[i][n-vert-1]) << " ";

        for(i = n-vert-2; i >= vert; i--)
            cout << p(arr[n-hor-1][i]) << " ";

        for(i = n-hor-2; i > hor; i--)
            cout << p(arr[i][vert]) << " ";

        hor++;
        vert++;
    }

    if(hor%2 == 0) 
        p = f; 
    else 
        p = g;

    if(n%2)
    {
        for(i = vert; i < n-vert; i++)
            cout << p(arr[hor][i]) << " ";
    }
    else
    {
        for(i = hor; i < n-hor; i++)
            cout << p(arr[i][vert]) << " ";
    }
}

void print(int arr[][MAX_SIZE], int n)
{ 
    int i, j;
    for(i = 0; i < n; i++)
    { 
        for(j = 0; j < n; j++)
            cout << setw(5) << arr[i][j];
        cout << endl;
    }
}

int plus1(int x)
{ 
    return x+1;
}

int plus2(int x)
{ 
    return x+2;
}

int main()
{ 
    int arr[MAX_SIZE][MAX_SIZE];
    int n, i, j;
    cout << "n= ";
    cin >> n;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        { 
            cout << "a[" << i << "][" << j << "]= ";
            cin >> arr[i][j];
        }
    }
    print(arr, n);

    spiralWalk(arr, n, plus2, plus1);
    cout << endl;
    return 0;
}

