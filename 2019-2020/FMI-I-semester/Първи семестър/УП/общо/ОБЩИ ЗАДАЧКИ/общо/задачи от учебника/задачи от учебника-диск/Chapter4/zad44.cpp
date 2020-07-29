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

// намиране на сумата от елементите на подредица
// на редицата v[0], v[1], Е, v[k-1]
int Sum(int n, int x[])
{ 
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        s = s + v[x[i]];
    }
    return s;
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

// генериране на подредиците и извеждане на онези, сумата
// от елементите на които са в интервала [p, q]
void WriteSubSeq(int k, int n, int p, int q)
{ 
    int a[MAX_SIZE];
    int i, j;

    // конструиране на първата вариаци€ с повторени€
    for(i = 0; i < n; i++)
    {
        a[i] = 0;
    }

    if(n == 1)	// вариаци€та е комбинаци€
    { 
        int s = Sum(n, a);
        if(s >= p && s <= q)
        {

            Write(n, a);   // извеждане на комбинаци€та с търсеното свойство
        }
    }

    int t = Pow_int(k, n);	// брой на вариациите с повторени€
    for(j = 1; j < t; j++)
    {
        if(a[n-1] < k-1)
									{  // намиране на следваща вариаци€
            // с повторени€ по правило а)
            a[n-1] = a[n-1] + 1;
            int s = Sum(n, a);
            if(Monotone(n, a) && s >= p && s <= q)
            {
                Write(n, a);    // извеждане на комбинаци€ с търсеното свойство
            }
        }
        else
									{  // намиране на следваща вариаци€
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

            int s = Sum(n, a);
            if(Monotone(n, a) && s >= p && s <= q)
            {
                Write(n, a);     // извеждане на комбинаци€ с търсеното свойство
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

    int p, q;
    do
    {
        cout << "p= ";
        cin >> p;
        cout << "q= ";
        cin >> q;
    } while(p > q);

    WriteSubSeq(k, n, p, q);
    return 0;
}
