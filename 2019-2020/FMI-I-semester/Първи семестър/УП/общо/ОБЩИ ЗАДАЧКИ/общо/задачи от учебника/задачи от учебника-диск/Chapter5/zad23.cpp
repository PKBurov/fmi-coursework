#include <iostream.h>

int func(int n, int i)
{
    if(i > n) return 0;

    int k = i*i*i + 13*i*n + n*n*n;
    if(k % 5 == 0 || k % 9 == 0) 
    {
        return 1+func(n, i+1);
    }
    return func(n, i+1);
}

int func(int n)
{
    return func(n, 1);
}

int main()
{
    int n;
    cout << "Въведете стойност за n (n >= 1): "; 
    cin >> n;
    cout << func(n) << endl;
    return 0;
}
