#include <iostream.h>

const int MAX_SIZE = 20;

void InsertInSort(int x, int& n, int a[])
{ 
    if(n == 0)
    {
        a[0]= x; n++;
    }
    else
    {
        if(x > a[n-1])
        { 
            n++;
            a[n-1] = x;
        }
        else
        { 
            n++;
            a[n-1] = a[n-2];
            int p = n-2;
            InsertInSort(x, p, a);
        }
    }
}

void ReadRed(int n, int a[])
{ 
    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }
}

void WriteRed(int n, int a[])
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << "  " ;
    }
    cout << endl;
}	

int main()
{
    int n;
    do
    {
        cout << "n= "; cin >> n;
    }while (n < 0);

    int a[MAX_SIZE];
    ReadRed(n, a);
    int x;
    cout << "x= "; cin >> x;
    InsertInSort(x, n, a);
    WriteRed(n, a);
    return 0;
}
