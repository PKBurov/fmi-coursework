#include <iostream.h>

int main() 
{
    cout << "Въведете стойност за n (n>=1): ";
    int n; 
    cin >> n;
    int f = 1;
    for(int i = 3; i <= 2*n-1; i = i+2)
    {
        f = f*i;
    }
    cout << "f= " << f << endl;
    return 0;
}
