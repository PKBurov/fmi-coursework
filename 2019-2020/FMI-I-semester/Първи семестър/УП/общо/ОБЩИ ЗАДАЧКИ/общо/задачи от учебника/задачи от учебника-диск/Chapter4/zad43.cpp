#include <iostream.h>
const int MAX_SIZE = 10;
int v[MAX_SIZE];

// извеждане на текуща комбинаци€
void Write(int k, int x[])
{ 
    for(int i = 0; i < k; i++)
    {
        cout << v[x[i]] << " ";
    }
    cout << endl;
}

// повдигане n на степен m
int Pow_int(int n, int m)
{ 
    int y = 1;
    for(int i = 1; i <= m; i++)
    {
        y = y*n;
    }
    return y;
}

// провер€ва дали редицата x[0], x[1], Е, x[k-1]
// е строго монотонно раст€ща
bool Monotone(int k, int x[])
{
    if(k == 1) 
        return true;

    int i = -1;
    do
    {
        i++;
    }while(x[i] < x[i+1] && i < k-2);

    return x[i] < x[i+1];
}

// генериране на комбинациите
void WriteCombinations(int n, int k)
{ 
    int a[MAX_SIZE];
    // конструиране на първата вариаци€ с повторени€

    int i, j;
    for(i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    if(n == 1)
    {
        Write(n, a);	            // вариаци€та е комбинаци€
    }

    int p = Pow_int(k, n);	      // брой на вариациите с повторени€
    for(j = 1; j < p; j++)
    {
        if(a[n-1] < k-1)
        { 
            // намиране на следваща вариаци€
            // с повторени€ по правило а)
            a[n-1] = a[n-1] + 1;
            if(Monotone(n, a))
            {

                Write(n, a);      // извеждане на комбинаци€та
            }
        }
        else
        { 
            // намиране на следваща вариаци€
            // с повторени€ по правило б)
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
            if(Monotone(n, a))
            {

                Write(n, a);        // извеждане на комбинаци€та
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
        cout << "k(k>=n)= ";
        cin >> k;
    } while(n > k);

    int i;
    for(i = 0; i < k; i++)
    {
        cout << "v[" << i << "]= ";
        cin >> v[i];
    }

    WriteCombinations(n, k);
    return 0;
}
