#include <iostream.h>
#include <iomanip.h>
#include <math.h>

int main()
{ 
    double x;

    do
    { 
        cout << "Въведете стойност на x от интервала (-1, 1): ";
        cin >> x;
    } while(fabs(x) >= 1);

    cout << "Въведете стойност на a: ";
    double a; 
    cin >> a;

    double eps; 
    do
    {
        cout << "Въведете стойност на eps (0, 0.1]: ";
        cin >> eps;
    } while(eps <= 0 || eps > 0.1);

    // намиране на сумата
    double x1 = 1, s = x1;
    int i = 0;
    while(fabs(x1) >= eps)
    { 
        x1 = x1*(a-i)*x/(i+1);
        s = s + x1;
        i++;
    }

    cout << setiosflags(ios::fixed) << setprecision(12);
    cout << "s= " << s << endl;
    return 0;
}
