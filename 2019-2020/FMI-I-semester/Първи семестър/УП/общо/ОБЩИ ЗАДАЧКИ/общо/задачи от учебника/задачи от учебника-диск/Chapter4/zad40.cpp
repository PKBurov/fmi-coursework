#include <iostream.h>
const int MAX_SIZE = 20;

// извежда текуща вариация с повторения
void Write(int k, int x[])
{
    for(int i = 0; i < k; i++)
        cout << x[i] << " ";
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

void WriteVariations(int n)
{
    // конструиране и извеждане на вариациите с повторения
    // на елементите 0 и 1 от n-ти клас
    // конструиране на първата вариация
    int a[MAX_SIZE];
    int i;
    for(i = 0; i < n; i++)
        a[i] = 0;

    // извеждане на вариацията
    Write(n, a);
    int p = Pow_int(2, n);	// брой на вариациите с повторения
    for(int j = 1; j < p; j++)
    {
        if(a[n-1] == 0)
        {
            // намиране на следваща вариация по правило а)
            a[n-1] = 1;
            Write(n, a);
        }
        else
        {
            // намиране на следваща вариация по правило б)
            int m = n-1;
            while(a[m] == 1) 
                m = m-1;

            a[m] = 1;
            for(i = m+1; i < n; i++)
                a[i] = 0;
            Write(n, a);
        }
    }
}

int main()
{ 
    cout << "n= ";
    int n; cin >> n;
    WriteVariations(n);
    return 0;
}
