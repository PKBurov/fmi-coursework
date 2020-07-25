#include <iostream.h>
const int MAX_SIZE = 100;

int input(int a[])
{
    int n, i;
    cout << "Въведете число в интервала 2.." 
         << MAX_SIZE << " ";
    cin >> n;
    while(n < 2 || n > MAX_SIZE)
    {
        cout << "Входна грешка!" << endl;
        cout << "Въведете число в интервала 2.." 
             << MAX_SIZE << " ";
        cin >> n;
    }

    for(i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }
    return n;
}

// обръща елементите с индекси от l до r
void reverse(int a[], int l, int r)
{
    int i = l, j = r;
    int tmp;
    while(i < j)
    {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        ++i, --j;
    }
}

void movelast(int a[], int n, int k)
{
    reverse(a, 0, k-1);
    reverse(a, k, n-1);
    reverse(a, 0, n-1);
}

void print(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, k, a[MAX_SIZE];
    n = input(a);

    cout << "k от 1 до " << n << "= ";
    cin >> k;
    if(k <= 0 || k > n)
    {
        cout << "Грешен вход!" << endl;
        return 1;
    }

    print(a, n);
    movelast(a, n, k);
    print(a, n);
    return 0;
}
