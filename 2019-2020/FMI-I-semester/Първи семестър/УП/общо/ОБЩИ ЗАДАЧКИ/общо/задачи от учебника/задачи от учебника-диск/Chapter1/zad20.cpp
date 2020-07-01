#include <iostream.h>
#include <math.h>

int main()
{
    int x = 0,
        k = 0;
    cout << "x= ";
    cin >> x;
    cout << "k (k >= 1)= ";
    cin >> k;
    cout << k << "-тата цифра на " << x << " e "
         <<  x/(int)pow(10.0, k-1)%10 << "\n";
    return 0;
}
