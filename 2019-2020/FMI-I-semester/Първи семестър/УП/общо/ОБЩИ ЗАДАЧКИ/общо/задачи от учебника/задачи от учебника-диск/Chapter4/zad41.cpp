#include <iostream.h>
const int MAX_SIZE = 10;

// извежда текуща вариация с повторения
int v[MAX_SIZE];
void Write(int k, int x[])
{
    for(int i = 0; i < k; i++)
        cout << v[x[i]] << " ";
    cout << endl;
}

// повдига n на степен m
int Pow_int(int n, int m)
{
    int y = 1;
    for(int i = 1; i <= m; i++)
        y = y*n;
    return y;
}

// конструира и извежда вариациите с повторения
// на елементите 0, 1, ..., k-1 от n-ти клас
void WriteVariations(int n, int k)
{
    int a[MAX_SIZE];
    // конструиране на първата вариация с повторения
    int i;
    for(i = 0; i < n; i++)
        a[i] = 0;

    // извеждане на първата вариация с повторения
    Write(n, a);

    int p = Pow_int(k, n);	// брой на вариациите с повторения
    for(int j = 1; j < p; j++)
    {
        if(a[n-1] < k-1)
        { 
            // намиране на следваща вариация по правило а)
            a[n-1] = a[n-1]+1;
            Write(n, a);
        }
        else
        { 
            // намиране на следваща вариация по правило б)
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
            Write(n, a);
        }
    }
}

int main()
{ 
    cout << "n= ";
    int n; cin >> n;
    cout << "k= ";
    int k; 
    cin >> k;

    int i;
    for(i = 0; i < k; i++)
    {
        cout << "v[" << i << "]= ";
        cin >> v[i];
    }
    WriteVariations(n, k);
    return 0;
}
