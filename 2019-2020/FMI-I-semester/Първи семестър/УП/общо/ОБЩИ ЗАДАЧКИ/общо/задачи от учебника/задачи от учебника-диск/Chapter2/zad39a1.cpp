#include <iostream.h>

int main() 
{
    cout << "Въведете стойност за n (n>=1): ";
    int n;
    cin >> n;
    int y = 2;
    int f = 2;
    for(int i = 2; i <= n; i++)
    {
        y = 2*i;
        f = f*y;
    }
    cout << "f= " << f << endl;
    return 0;
}
