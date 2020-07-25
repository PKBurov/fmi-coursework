#include <iostream.h>
#include <iomanip.h>

const int MAX_SIZE = 100;

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

void print(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << setw(5) << a[i];
    }
    cout << endl;
}

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

// Реализира двоично търсене в сортиран масив
int search(int a[], int n, int elem)
{
    int l, r, mid;          // индекс на ляв, десен и среден елемент
    l = 0;
    r = n-1;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(a[mid] == elem)  // Елементът е намерен
        {
            return mid;
        }
        if(a[mid] < elem)   // търсене в дясната част
        {
            l = mid + 1;
        }
        else                // търсене в лявата част
        {
            r = mid - 1;
        }
    }
    return -1;              // елементът не е намерен
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
                "във възходящ ред! \n";
        return 1;
    }

    cout << "Елемент за търсене: ";
    cin >> num;
    if((ind = search(a, n, num)) >= 0)
    {
        cout << "Елементът е намерен на позиция: " << ind << endl;
    }
    else
    {
        cout << "Елементът не е намерен! \n" << endl;
    }
    return 0;
}
