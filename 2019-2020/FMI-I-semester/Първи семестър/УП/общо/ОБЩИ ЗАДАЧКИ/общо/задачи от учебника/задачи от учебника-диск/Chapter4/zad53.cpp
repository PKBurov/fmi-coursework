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
        {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
}

void printDiags1(int a[][MAX], int n)
{
    int i, j;
    for(i = 1 - n; i <= 0; i++)
    {
        for(j = -i; j < n ; j++)
        {
            cout << setw(4) << a[j+i][j];
        }
    }

    for(i = 1; i < n; i++)
    {
        for(j = 0; j < n - i; j++)
        {
            cout << setw(4) << a[j+i][j];
        }
    }
    cout << endl;
}

void printDiags2(int a[][MAX], int n)
{
    for(int i = 1 - n; i < n; i++)
    {
        for(int j = (i > 0) ? 0 : -i; j < n - i && j < n ; j++)
        {
            cout << setw(4) << a[j+i][j];
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

    printDiags1(a, n); cout << endl;
    printDiags2(a, n);

    return 0;
}
