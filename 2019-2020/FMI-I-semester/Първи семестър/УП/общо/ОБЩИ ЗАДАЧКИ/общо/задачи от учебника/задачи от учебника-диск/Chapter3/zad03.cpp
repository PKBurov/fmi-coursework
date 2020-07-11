#include <iostream.h>
const int MAX_SIZE = 30;

int main()
{
    cout << "Въведете стойност на n – цяло число от 1 до "
         <<  MAX_SIZE << ": ";
    int n; 
    cin >> n;
    double a[MAX_SIZE];

    // Въвеждане на елементите на редицата
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    // намиране на сумата и на произведението
    double sum = 0,    // ще съдържа сумата
           prod = 1;   // ще съдържа произведението
    for(i = 0; i < n; i++)
    {
        if(a[i] > 0) 
        {
            sum = sum + a[i];
        }
        else if (a[i] < 0) 
        {
            prod = prod * a[i];
        }
    }

    // извеждане на резултата
    cout << "sum= " << sum << endl
         << "prod= " << prod << endl;
    return 0;
}
