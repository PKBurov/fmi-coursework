#include <iostream.h>

int main()
{
    cout << "Въведете стойност за n (n>=1): ";
    int n; 
    cin >> n;
    int f;
    if(n%2 == 0)
    {
        f = 1;
        for(int i = 2; i <= n; i = i+2)
        {
            f = f*i;
        }
    }
    else
    { 
        f = 1;
        for(int i = 3; i <= n; i = i+2)
        {
            f = f*i;
        }
    }
    cout << "f= " << f << endl;
    return 0;
}
