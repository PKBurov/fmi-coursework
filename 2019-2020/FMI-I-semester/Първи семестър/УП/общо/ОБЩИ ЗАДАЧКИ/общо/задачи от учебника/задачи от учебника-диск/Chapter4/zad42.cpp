#include <iostream.h>
const int MAX_SIZE = 10;
int v[MAX_SIZE];

// извежда текуща вариация без повторения
void Write(int k, int x[])
{
    for(int i = 0; i < k; i++)
    {
        cout << v[x[i]] << " ";
    }
    cout << endl;
}

// повдига n на степен m
int Pow_int(int n, int m)
{
    int y = 1;
    for(int i = 1; i <= m; i++)
    {
        y = y*n;
    }
    return y;
}

// проверява дали елементите на редицата
// x[0], x[1], …, x[k-1] са различни
bool Different(int k, int x[])
{ 
    if(k == 1)
    {
        return true;
    }

    int i = -1, j;
    do
    { 
        i++;
        j = i;
        do
        {
            j++;
        }while(x[i] != x[j] && j < k-1);
    } while(x[i] != x[j] && i < k-2);

    return x[i] != x[j];
}

// генерира вариациите без повторения
void WriteVariations(int n, int k)
{ 
    int a[MAX_SIZE];
    int i, j;

    // конструиране на първата вариация с повторения
    for(i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    if(n == 1)
    {
        Write(n, a);                // вариацията е без повторения
    }
    int p = Pow_int(k, n);	        // брой на вариациите с повторения

    for(j = 1; j < p; j++)
    {
        if(a[n-1] < k-1)
        { 
            // намиране на следваща вариация
            // с повторения по правило а)
            a[n-1] = a[n-1] + 1;
            if(Different(n, a))
            {
                Write(n, a);        // извеждане на вариация без повторения
            }
        }
        else
        { 
            // намиране на следваща вариация
            // с повторения по правило б)
            int m = n-1;
            while(a[m] == k-1)
            {
                m = m-1;
            }
            a[m] = a[m]+1;
            for(i = m+1; i < n; i++)
            {
                a[i] = 0;
            }
            if(Different(n, a)) 
            {
                Write(n, a);        // извеждане на вариация без повторения
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
        cout << "k(k >= n)= ";
        cin >> k;
    } while(n > k);

    int i;
    for(i = 0; i < k; i++)
    {
        cout << "v[" << i << "]= ";
        cin >> v[i];
    }
    WriteVariations(n, k);
    return 0;
}
