#include <iostream.h>
#include <iomanip.h>

const int MAX_N = 5;

// въвеждане на редица от n цели числа
void init(int a[], int& n)
{
    do
    {
        cout << "n= ";
        cin >> n;
    } while(n <= 0 || n > MAX_N);

    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }
}

// извеждане на редица от n цели числа
void print(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << setw(5) << a[i];
    }
    cout << endl;
}

// помощна функция, която обръща елементите на
// подредицата а[i], a[i+1], …, a[n-1]
void print_rev_help(int a[], int n, int i)
{
    if(i == n) 
        return;

    print_rev_help(a, n, i+1);
    cout << setw(5) << a[i];
}

void print_rev(int a[], int n)
{
    print_rev_help(a, n, 0);
    cout << endl;
}

int main()
{
    int a[MAX_N], n;
    init(a, n);
    print(a, n);
    print_rev(a, n);
    return 0;
}
