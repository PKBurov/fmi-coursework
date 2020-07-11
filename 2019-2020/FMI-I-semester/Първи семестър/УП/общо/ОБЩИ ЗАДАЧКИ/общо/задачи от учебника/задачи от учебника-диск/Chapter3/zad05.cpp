#include <iostream.h>
const int MAX_SIZE = 10;

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

    // намиране на произведението
    int prod = 1;   // ще съдържа произведението
    int k = 2;
    for(i = 3; i < n; i++)
    {
        k = k*i;      // съдържа i!
        if(a[i] > 2 && a[i] < k)
        {
            prod = prod*a[i];
        }
    }

    // извеждане на резултата
    cout << "Реципрочното на произведението число е: "
         << 1./prod << endl;
    return 0;
}
