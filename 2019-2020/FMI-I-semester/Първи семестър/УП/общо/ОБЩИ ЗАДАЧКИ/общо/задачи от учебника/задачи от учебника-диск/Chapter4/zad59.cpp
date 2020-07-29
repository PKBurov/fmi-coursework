#include <iostream.h>
#include <iomanip.h>

const int MAX_SIZE = 20;

// въвеждане на матрица по редове
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

// извеждане на матрица по редове
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

// копиране на матрицата From в матрицата To
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

// пресмятане на логическото произведение C = A * B
// на квадратните матрици A и B
void mul(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for(int l = 0; l < n; l++)
            {
                C[i][j] = C[i][j] || A[i][l] && B[l][j];
            }
        }
    }
}

int main()
{ 
    int A[MAX_SIZE][MAX_SIZE],
        B[MAX_SIZE][MAX_SIZE],
        C[MAX_SIZE][MAX_SIZE];
    int n, l;

    cout << "Брой върхове на графа: ";
    cin >> n;

    cout << "Въведете матрицата на съседство на графа: \n";
    ReadMatrix(n, A);
    // извеждане на матрицата на съседство на графа
    WriteMatrix(n, A); cout << endl;

    cout << "Начален град: ";
    int beg; 
    cin >> beg;

    cout << "Краен град: ";
    int end;
    cin >> end;

    cout << "Дължина на пътя: ";
    int k;
    cin >> k;

    copy(A, B, n);  // копира матрицата A в матрицата B

    // намиране на A на степен k (в матрицата C)
    for(l = 2; l <= k; l++)
    { 
        mul(B, A, C, n);
        copy(C, B, n);
    }

    if(C[beg][end]) 
    {
        cout << "Има път с дължина " << k << endl;
    }
    else
    {
        cout << "Няма път с дължина " << k << endl;
    }
    return 0;
}
