#include <iostream.h>
const int MAX_SIZE = 10;

// извеждане на позици€ на n топа
void Write(int n, int a[])
{
    for(int i = 0; i < n; i++)
    {
        cout << "(" << i+1 << ", " << a[i]+1 << ") ";
    }
    cout << "\n\n";
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

// провер€ване дали позици€та е правилна
bool CorrectPosition(int n, int a[])
{ 
    int i, j; 
    bool flag = true;
    for(i = 0; i < n-1 && flag; i++)
    {
        for(j = i+1; j < n && flag; j++)
        {
            if(a[i] == a[j]) 
            {
                flag = false;
            }
        }
    }
    return flag;
}

// генериране и извеждане на всички правилни позиции на n топа
void N_Castles(int n)
{ 
    int i, j;
    // носител на вариаци€ с повторени€ на елементите
    // 0, 1, 2, ... n-1 от n-ти клас 
    int a[MAX_SIZE];

    // конструиране на всички вариации с повторени€
    // на елементите 0, 1, ..., n-1 от n-ти клас
    // конструиране на първата вариаци€ с повторени€
    for(i = 0; i < n; i++)
    {
        a[i] = 0;
    }

    if(CorrectPosition(n, a)) 
    {
        Write(n, a);
    }

    // конструиране на останалите вариации с повторени€
    int p = Pow_int(n,n);
    for(j = 1; j < p; j++)
    {
        if(a[n-1] < n-1)
        {
            a[n-1] = a[n-1]+1;      // намиране на следваща вариаци€
        }
        else
        {   // намиране на следваща вариаци€
            int m = n-1;
            while(a[m] == n-1)
            {
                m = m-1;
            }
            a[m] = a[m]+1;
            for(i = m+1; i < n; i++)
            {
                a[i] = 0;
            }
        }
        if(CorrectPosition(n, a)) 
        {
            Write(n, a);
        }
    }
}

int main()
{
    cout << "–азмер на шахматната дъска n: ";
    int n; 
    cin >> n;

    N_Castles(n);
    return 0;
}
