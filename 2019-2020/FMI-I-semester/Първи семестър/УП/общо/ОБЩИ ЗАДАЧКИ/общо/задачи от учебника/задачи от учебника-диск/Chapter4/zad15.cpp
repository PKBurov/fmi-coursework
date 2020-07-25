#include <iostream.h>
#include <iomanip.h>

const int MAX_SIZE = 100;

// Въвежда едномерен масив
int init(int a[])
{
    int n;
    do
    {
        cout << "Въведете размер на масива между 1 и "
             << MAX_SIZE << endl;
        cin >> n;
    } while(n <= 0 || n > MAX_SIZE);

    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }
    return n;
}

// Извежда елементите на едномерен масив
void print(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << setw(5) << a[i];
    }
    cout << endl;
}

// Обръща елементите на едномерен масив
void reverse(int a[], int size)
{
    int tmp;
    for(int i = 0; i < size/2; i++)
    {
        tmp = a[i];
        a[i] = a[size-i-1];
        a[size-i-1] = tmp;
    }
}

int main()
{
    int a[MAX_SIZE];
    int n = init(a);
    print(a, n);
    reverse(a, n);
    print(a, n);
    return 0;
}
