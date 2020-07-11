#include <iostream.h>
#include <math.h>
const int MAX_SIZE = 100;

int main()
{
    cout << "Въведете стойност на реалната променлива x: ";
    double x;
    cin >> x;
    cout << "Въведете стойност на n – цяло число от 2 до "
         <<  MAX_SIZE << ": ";
    int n; 
    cin >> n;
    double a[MAX_SIZE];

    // Въвеждане на елементите на редицата a
    int i;
    cout << "Въведете " << n
         << " различни реални числа\n";
    for(i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    // Въвеждане на елементите на редицата b
    cout << "Въведете " << n 
         << " реални числа\n";
    double b[MAX_SIZE];
    for(i = 0; i < n; i++)
    {
        cout << "b[" << i << "]= ";
        cin >> b[i];
    }

    int j; double S = 0;
    for(i = 0; i < n; i++)
    {
        double p = 1;
        for(j = 0; j < n; j++)
        {
            if(j != i) 
            { 
                double temp = cos(a[i])-cos(a[j]);
                if(temp)
                {
                    p = p *(sin(x) - sin(a[j])) / temp;
                }
                else
                { 
                    cout << "Стойността на израза е неопределена!\n";
                    return 1;
                }
            }
        }
        S = S + b[i]*p;
    }
    cout << "S= " << S << endl;
    return 0;
}
