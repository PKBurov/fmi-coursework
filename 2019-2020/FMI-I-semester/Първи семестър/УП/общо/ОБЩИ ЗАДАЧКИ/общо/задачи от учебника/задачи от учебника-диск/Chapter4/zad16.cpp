#include <iostream.h>
#include <iomanip.h>

const int MAX_SIZE = 100;

// Въвеждане на едномерен масив
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

// Извеждане на едномерен масив
void print(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << setw(5) << a[i];
    }
    cout << endl;
}

// Проверяване дали масив е сортиран във възходящ ред
bool isSorted(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        if(a[i] > a[i+1])
        {
            return false;
        }
    }
    return true;
}

// Последователно търсене в сортиран масив
int search(int a[], int n, int elem)
{ 
    int i = 0;
    while(i < n && a[i] < elem)
    {
        ++i;
    }
    if(i < n && a[i] == elem)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int a[MAX_SIZE];
    int n, num, ind;
    n = init(a);
    print(a, n);
    if(!isSorted(a, n))
    {
        cout << "Масивът трябва да е сортиран "
             << "във възходящ ред!\n";
        return 1;
    }
    cout << "Елемент за търсене: ";
    cin >> num;
    if((ind = search(a, n, num)) >= 0)
    {
        cout << "Намерен е на позиция: " << ind << endl;
    }
    else
    {
        cout << "Не е намерен!\n" << endl;
    }
    return 0;
}

