#include <iostream.h>
#include <iomanip.h>

const int MAX = 100;

void print(int a[][MAX], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }
}

void fill1(int a[][MAX], int n, int m)
{
    int num = 1;
    for(int i = 0; i < n; i++)
    {
        if(i % 2)
        {
            for(int j = m-1; j >= 0; j--)
            {
                a[i][j] = num++;
            }
        }
        else
        {
            for(int j = 0; j < m; j++)
            {
                a[i][j] = num++;
            }
        }
    }
}

void fill2(int a[][MAX], int n, int m)
{ 
    int num, i;
    for(i = 0; i < n; i += 2)
    { 
        num = m*i + 1;
        for(int j = 0; j < m; j++)
        {
            a[i][j] = num++;
        }
    }

    for(i = 1; i < n; i += 2)
    {
        num = m*(i+1);
        for(int j = 0; j < m; j++)
        {
            a[i][j] = num--;
        }
    }
}


void fill3(int a[][MAX], int n, int m)
{
    int num = 1;
    int dir = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = (i%2) ? m-1 : 0; j >= 0 && j < m; j += dir)
            a[i][j] = num++;
        dir *= -1;
    }
}

int main()
{
    int a[MAX][MAX];
    int n, m;

    do
    {
        cout << "n= ";
        cin >> n;
        cout << "m= ";
        cin >> m;
    } while(n <= 0 || n > MAX || m <= 0 || m > MAX);

    fill1(a, n, m);
    print(a, n, m); cout << endl;

    fill2(a, n, m);
    print(a, n, m); cout << endl;

    fill3(a, n, m);
    print(a, n, m); cout << endl;

    return 0;
}
