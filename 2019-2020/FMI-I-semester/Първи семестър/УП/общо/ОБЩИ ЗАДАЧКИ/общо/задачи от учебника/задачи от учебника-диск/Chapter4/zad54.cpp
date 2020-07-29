#include <iostream.h>
#include <iomanip.h>

const int MAX = 100;

void print(int a[][MAX], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }	
}

void init(int a[][MAX], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
}

// Пресмята C = A + B
// И трите матрици имат размерност n x m
void sum(int A[][MAX], int B[][MAX],int C[][MAX], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Пресмята C = A - B
// И трите матрици имат размерност n x m
void dif(int A[][MAX], int B[][MAX],int C[][MAX], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Пресмята C = A * B
// A е с размерност n x m; B - с размерност m x k
// C е с размерност n x k
void mul(int A[][MAX], int B[][MAX],int C[][MAX], int n, int m, int k)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        { 
            C[i][j] = 0;
            for(int l = 0; l < m; l++)
            {
                C[i][j] += A[i][l] * B[l][j];
            }
        }
    }
}

int main()
{
    int n, m, k;
    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];
    cout << "n= ";
    cin >> n;

    cout << "m= ";
    cin >> m;

    cout << "\nEnter A:\n";
    init(A, n, m);

    cout << "\nEnter B:\n";
    init(B, n, m);

    sum(A, B, C, n, m);
    cout << "\n A: \n";
    print(A, n, m);
    cout << "\n B: \n";
    print(B, n, m);
    cout << "\n A + B \n";
    print(C, n, m);

    dif(A, B, C, n, m);
    cout << "\n A: \n";
    print(A, n, m);
    cout << "\n B: \n";
    print(B, n, m);
    cout << "\n A - B \n";
    print(C, n, m);

    cout << "k= ";
    cin >> k;
    cout << "\nEnter A:\n";
    init(A, n, m);
    cout << "\nEnter B:\n";
    init(B, m, k);

    mul(A, B, C, n, m, k);
    cout << "\n A: \n";
    print(A, n, m); 
    cout << endl;
    cout << "\n B: \n";
    print(B, m, k); 
    cout << endl;
    cout << "\n A * B \n";
    print(C, n, k); 
    cout << endl;
    return 0;
}
