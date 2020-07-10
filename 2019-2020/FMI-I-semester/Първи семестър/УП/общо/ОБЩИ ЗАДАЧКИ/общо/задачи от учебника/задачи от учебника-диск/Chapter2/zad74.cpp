#include <iostream.h>

int main()
{ 
    cout << "Въведете стойности на m и n (0 <= m < n): ";
    int m, n; 
    cin >> m >> n;

    // конструиране на числата на Фибоначи, по-малки от m
    int a = 0, b = 1;
    while(a < m)
    { 
        int c = a;
        a = a + b;
        b = c;
    }

    // сумиране на числата на Фибоначи от интервала [m, n]
    int sum = 0;
    while(a <= n)
    {
        sum = sum+a;
        int c = a;
        a = a + b;
        b = c;
    }
    cout << "Сумата на числата на Фибоначи от интервала ["
         << m << ", " << n << "] е " << sum << endl;
    return 0;
}
