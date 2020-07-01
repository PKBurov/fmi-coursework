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

    double S = 1, a = 1;
    for(int i = 2; i <= n; i = i+1)
    { 
        if(i%3 == 0) 
        {
            a = -2;
        }
        else
        {
            a = 1;
        }
        S = S + a/i;
    }
    cout << "Сумата е  " << S << endl;
    cout << log(3) << endl;
    return 0;
}
