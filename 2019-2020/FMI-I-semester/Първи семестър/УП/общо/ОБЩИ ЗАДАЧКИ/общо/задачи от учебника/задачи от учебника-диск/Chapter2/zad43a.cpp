#include <iostream.h>
#include <math.h>

int main()
{
    int n;
    do
    {
        cout << "Въведете стойност за n (n >= 1): ";
        cin >> n;
    } while(n < 1);

    double S = 1, k = 1;
    for(int i = 2; i <= n; i = i+1)
    {
        k = -k;
        S = S + k/i;
    }
    cout << "Сумата е  " << S << endl;
    cout << log(2) << endl;
    return 0;
}
