#include <iostream.h>

bool pow2(int n)
{ 
    if(n == 1) return true;
    if(n%2 == 1) return false;
    return pow2(n/2);
}

int main()
{ 
    int n;
    do
    {
        cout << "Въведете стойност на n(n>=1): ";
        cin >> n;
    } while (n<1);

    if(pow2(n))
    {
        cout << n << " е степен на 2.\n";
    }
    else
    {
        cout << n << " не е степен на 2.\n";
    }
    return 0;
}
