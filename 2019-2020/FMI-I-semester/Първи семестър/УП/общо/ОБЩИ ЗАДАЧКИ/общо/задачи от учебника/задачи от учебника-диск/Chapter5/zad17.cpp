#include <iostream.h>
#include <iomanip.h>

void print(unsigned int n)
{ 
    if(n == 1) return;

    for(unsigned int i = 2; i <= n; i++)
    {
        if(n % i == 0)
        {
            cout << setw(5) << i;
            print(n/i);
            return;
        }
    }
}
