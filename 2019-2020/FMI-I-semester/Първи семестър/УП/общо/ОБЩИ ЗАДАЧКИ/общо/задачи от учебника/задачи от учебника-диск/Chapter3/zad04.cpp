#include <iostream.h>
const int MAX_SIZE = 100;

int main()
{ 
    cout << "Въведете стойност на n – цяло число от 1 до "
         <<  MAX_SIZE << ": ";
    int n; 
    cin >> n;
    double x[MAX_SIZE];

    // Въвеждане на елементите на редицата
    int i;
    cout << "Въведете " << n 
         << " различни от 0 реални числа\n";
    for(i = 0; i < n; i++)
    {
        cout << "x[" << i << "]= ";
        cin >> x[i];
    }

    // намиране на стойността на израза F
    double F = 0;
    for(i = 0; i < n; i++)
    {
        F = F + x[i]/x[n-i-1];
    }

    // извеждане на резултата
    cout << "F= " << F << endl;
    return 0;
}

