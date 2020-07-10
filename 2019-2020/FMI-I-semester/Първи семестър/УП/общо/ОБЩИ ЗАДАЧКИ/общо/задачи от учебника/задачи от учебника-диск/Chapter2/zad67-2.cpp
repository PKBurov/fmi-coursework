#include <iostream.h>
#include <math.h>

int main()
{ 
    int n;

    do
    { 
        cout << "Въведете неотрицателно цяло число: ";
        cin >> n;
    } while(n < 0);

    int len = (int)log10(n)+1;	// брой цифри на числото n
    int k = 1;

    for(int i = 1; i <= len; i++)
    { 
        if(n/k % 10 % 2 == 1)
        {
            n = n/(k*10)*k + n%k;
        }
        else 
        {
            k = k*10;
        }
    }
    cout << n << endl;
    return 0;
}
