#include <iostream.h>
#include <iomanip.h>

const int MAX_SIZE = 20;

// въвеждане на матрица по редове
void ReadMatrix(int k, int x[][MAX_SIZE])
{
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cin >> x[i][j];
        }
    }
}

// извеждане на матрица по редове
void WriteMatrix(int k, int x[][MAX_SIZE])
{ 
    for(int i = 0; i < k; i++)
    { 
        for(int j = 0; j < k; j++)
        {
            cout << setw(7) << x[i][j];
        }
        cout << endl;
    }
}

// извеждане на множество от градове
void Write(int k, int x[])
{
    for(int i = 0; i < k; i++)
    {
        cout << x[i]+1 << " ";
    }
    cout << endl;
}

// повдигане n на степен m
int Pow_int(int n, int m)
{ 
    int y = 1;
    for(int i = 1; i <= m; i++)
        y = y*n;
    return y;
}

// проверяване дали редица е строго монотонно растяща
bool Monotone(int k, int x[])
{ 
    if (k == 1) 
        return true;
    int i= -1;
    do
    {
        i++;
    }while(x[i] < x[i+1] && i < k-2);

    return x[i] < x[i+1];
}

// проверяване дали x[0],x[1], …, x[n-1] е пълно множество
bool Check(int b[][MAX_SIZE], int n, int x[])
{   // проверяване дали множеството
    // x[0], x[1], …, x[n-1] е независимо
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(b[x[i]][x[j]] == 1 || b[x[j]][x[i]] == 1)
                return false;
        }
    }
    return true;
}

void WriteCombinations(int n, int k, int b[][MAX_SIZE])
{ 
    int a[MAX_SIZE];

    // конструиране на първата вариация с повторения
    int i, j;
    for(i = 0; i < n; i++)
        a[i] = 0;

    int p = Pow_int(k, n);
    for(j = 1; j < p; j++)
    {
        if(a[n-1] < k-1)
        { // намиране на следваща вариация с повторения
            a[n-1] = a[n-1]+1;
            if(Monotone(n, a))
            {
                if(Check(b, n, a))
                {
                    Write(n, a);        // извеждане на пълно множество от градове
                }
            }
        }
        else
        { // намиране на следващата вариация с повторения
            int m = n-1;
            while(a[m]==k-1)
                m = m-1;
            a[m] = a[m]+1;
            for(i = m+1; i < n; i++)
                a[i] = 0;
            if(Monotone(n, a))
            {
                if(Check(b, n, a))
                {
                    Write(n, a);    // извеждане на пълно множество от градове
                }
            }
        }
    }
}

int main()
{
    int n, k;
    do
    {
        cout << "n= ";
        cin >> n;
        cout << "k(k>n)= ";
        cin >> k;
    } while(k < 3 || k > MAX_SIZE || n < 2 || n >= k);

    int b[MAX_SIZE][MAX_SIZE];
    ReadMatrix(k, b);
    WriteMatrix(k, b);
    WriteCombinations(n, k, b);
    return 0;
}
