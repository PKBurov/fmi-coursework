#include <iostream.h>
#include <iomanip.h>
#include <math.h>

typedef double(*type)(double);

const int MAX = 100;

void Read(double X[][MAX], int k)
{
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cin >> X[i][j];
        }
    }
}

void Write(double X[][MAX], int k)
{
    cout << setiosflags(ios::fixed) << setprecision(2);

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cout << setw(10) << X[i][j];
        }
        cout << endl;
    }
    cout << "\n\n";
}

void Map(double X[], int k, type f)
{
    for(int i = 0; i < k; i++)
        X[i] = f(X[i]);
}

void Mapf(double Y[][MAX], int k, type f)
{
    for(int i = 0; i < k; i++)
        Map(Y[i], k, f);
}

int main()
{
    cout << "n= ";
    int n; 
    cin >> n;
    double A[MAX][MAX];
    Read(A, n);
    Write(A, n);
    Mapf(A, n, fabs);
    Write(A, n);
    Mapf(A, n, sqrt);
    Write(A, n);
    return 0;
}

