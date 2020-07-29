#include <iostream.h>
#include <iomanip.h>

const int MAX_SIZE = 20;

// въвеждане на матрицата на теглата по редове
void ReadMatrix(double X[][MAX_SIZE], int k)
{
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cin >> X[i][j];
        }
    }
}

// извеждане на матрицата на теглата по редове
void WriteMatrix(double X[][MAX_SIZE], int k)
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

// копиране на матрицата на теглата X в матрицата Y
void Copy(double From[][MAX_SIZE], double To[][MAX_SIZE], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            To[i][j] = From[i][j];
        }
    }
}

// намиране на матрицата от дължините на най-късите пътища
void MinWays(double X[][MAX_SIZE], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            double Sum;
            if(X[i][j] < 1000)
            {
                for(int k = 0; k < n; k++)
                {
                    if(X[i][k] < 1000)
                    { 
                        Sum = X[j][i] + X[i][k];
                        if(Sum < X[j][k])
                            X[j][k] = Sum;
                    }
                }
            }
        }
    }
}

int main()
{ 
    double W[MAX_SIZE][MAX_SIZE],         // матрица на теглата
           MinWay[MAX_SIZE][MAX_SIZE];    // матрица на най-късите пътища
    int n;
    cout << "Брой върхове на графа: ";
    cin >> n;

    cout << "Въведете матрицата на теглата на графа: \n";
    ReadMatrix(W, n);

    // извеждане на матрицата на теглата на графа
    WriteMatrix(W, n); 
    cout << endl;

    Copy(W, MinWay, n); 	// копира матрицата A в матрицата B
    MinWays(MinWay, n);
    WriteMatrix(MinWay, n);
    cout << endl;
    return 0;
}

