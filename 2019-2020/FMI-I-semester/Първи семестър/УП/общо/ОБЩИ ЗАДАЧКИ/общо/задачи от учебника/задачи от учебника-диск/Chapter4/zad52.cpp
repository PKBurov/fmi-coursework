#include <iostream.h>
#include <iomanip.h> 

const int MAX = 20;

void print(int a[][MAX], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }
}

void init(int a[][MAX], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        { cout << "a[" << i << "][" << j << "]= ";
        cin >> a[i][j];
        }
    }
}

void printDiags1(int a[][MAX], int n)
{
    int i, j;
    cout << endl;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            cout << setw(4) << a[j][i-j];
        }
    }

    for(i = n; i < 2*n-1; i++)
    {
        for(j = i-n+1; j < n; j++)
        {
            cout << setw(4) << a[j][i-j];
        }
    }
    cout << endl;
}

void printDiags2(int a[][MAX], int n)
{
    cout << endl;
    for(int i = 0; i < 2*n-1; i++)
    {
        for(int j = (i < n) ? 0 : i-n+1; j < n && j <= i; j++)
        {
            cout << setw(4) << a[j][i-j];
        }
    }
    cout << endl;
}

int main()
{
    int a[MAX][MAX];
    int n;
    do
    {
        cout << "n= ";
        cin >> n;
    } while(n <= 0 || n > MAX);

    init(a, n);
    print(a, n);
    printDiags1(a, n);
    return 0;
} 
