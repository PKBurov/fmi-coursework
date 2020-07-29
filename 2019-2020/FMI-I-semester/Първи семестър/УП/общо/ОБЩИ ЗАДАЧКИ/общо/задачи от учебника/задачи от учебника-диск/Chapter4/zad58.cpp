#include <iostream.h>
#include <iomanip.h>

const int MAX_SIZE = 20;

// Въвеждане на матрица по редове
void ReadMatrix(int k, int X[][MAX_SIZE])
{ 
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cin >> X[i][j];
        }
    }
}

// Извеждане на матрица по редове
void WriteMatrix(int k, int X[][MAX_SIZE])
{ 
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cout << setw(7) << X[i][j];
        }
        cout << endl;
    }
}

// Намиране на M(k+1) по зададена M(k) 
void mul(int M[][MAX_SIZE], int MNext[][MAX_SIZE], int n, int k)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            MNext[i][j] = M[i][j] || M[i][k] && M[k][j];
        }
    }
}

// Създаване на копие To на матрицата From
void copy(int From[][MAX_SIZE], int To[][MAX_SIZE], int n)
{ 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            To[i][j] = From[i][j];
        }
    }
}

int main()
{
    int A[MAX_SIZE][MAX_SIZE],
        B[MAX_SIZE][MAX_SIZE];
    int n, l;

    cout << "n: ";
    cin >> n;

    cout << "Въведете матрицата на съседство на графа: \n";
    ReadMatrix(n, A);
    WriteMatrix(n, A);
    cout << endl;

    for(l = 0; l < n; l++)
    {
        mul(A, B, n, l);
        copy(B, A, n);  // копира матрицата B в матрицата A
    }
    cout << "Матрицата на свързаност е: \n";
    WriteMatrix(n, B);
    return 0;
}
