#include <iostream.h>
#include <iomanip.h>
#include <math.h>

int main()
{ 
    double x;
    do
    {
        cout << "Въведете стойност на x (-1, 1]: ";
        cin >> x;
    } while(x <= -1 || x > 1);

    double eps; 
    do
    {
        cout << "Въведете стойност на eps (0, 0.1]: ";
        cin >> eps;
    } while(eps <= 0 || eps > 0.1);

    // намиране на сумата
    cout << setiosflags(ios::fixed) << setprecision(12);
    double s;
    if(fabs(x) < eps)
    {
        s = x;
    }
    else
    {
        double temp = x*x,	// натрупва x2, –x3, x4, -x5, x6,…
               x1 = temp/2; // съдържа поредно събираемо
        s = x + x1;	        // натрупва сумата
        int i = 2;
        while(fabs(x1) >= eps)
        { 
            temp = -temp*x;		
            x1 = temp/(i*(i+1));
            s = s + x1;
            i++;
        }
    }
    cout << "s= " << s << endl;
    return 0;
}
