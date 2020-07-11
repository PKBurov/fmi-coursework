#include <iostream.h>
#include <math.h>
const int MAX_SIZE = 100;

int main()
{
    cout << "Въведете стойност на n – цяло число от 1 до "
         <<  MAX_SIZE << ": ";
    int n;
    cin >> n;
    int i;

    // Въвеждане на елементите на редицата x
    double x[MAX_SIZE];
    for(i = 0; i < n; i++)
    {
        cout << "x[" << i << "]= ";
        cin >> x[i];
    }

    // Въвеждане на елементите на редицата y
    double y[MAX_SIZE];
    for(i = 0; i < n; i++)
    {
        cout << "y[" << i << "]= ";
        cin >> y[i];
    }

    // намиране на сумите на израза
    double  sum1 = 0,  // ще съдържа x[0]+x[1]+ … + x[n-1]
            sum2 = 0,  // ще съдържа y[0]+y[1]+ … + y[n-1]
            sum3 = 0,  // ще съдържа x[0]*x[0]+ …+ x[n-1]*x[n-1]
            sum4 = 0,  // ще съдържа y[0]*y[0]+ …+ y[n-1]*y[n-1]
            sum5 = 0;  // ще съдържа x[0]*y[0]+ …+ x[n-1]*y[n-1]
    for(i = 0; i < n; i++)
    {
        sum1 = sum1 + x[i];
        sum2 = sum2 + y[i];
        sum3 = sum3 + x[i]*x[i];
        sum4 = sum4 + y[i]*y[i];
        sum5 = sum5 + x[i]*y[i];
    }

    double denom = (n*sum3-sum1*sum1)*(n*sum4-sum2*sum2);
    if(denom > 0)
    {
        double r = (n*sum5-sum1*sum2) / sqrt(denom);
        cout << "Коефициентът на корелация е " << r << endl;
    }
    else 
    {
        cout << "Коефициентът на корелация е неопределен.\n";
    }
    return 0;
}
