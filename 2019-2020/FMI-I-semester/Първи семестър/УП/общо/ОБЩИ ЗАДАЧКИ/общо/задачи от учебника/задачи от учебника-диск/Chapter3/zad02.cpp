#include <iostream.h>
const int MAX_SIZE = 100;

int main()
{
    cout << "Въведете стойност на n – цяло число от 1 до "
         <<  MAX_SIZE << ": ";
    int n; 
    cin >> n;
    int a[MAX_SIZE];

    // Въвеждане на елементите на редицата
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    // намиране на сумата от елементите на редицата,
    // които са удвоени нечетни числа
    int sum = 0;
    for(i = 0; i < n; i++)
    {
        if((a[i]-2)%4 == 0)
        {
            sum = sum + a[i];
        }
    }

    // извеждане на резултата
    cout << "sum= " << sum << endl;
    return 0;
}
