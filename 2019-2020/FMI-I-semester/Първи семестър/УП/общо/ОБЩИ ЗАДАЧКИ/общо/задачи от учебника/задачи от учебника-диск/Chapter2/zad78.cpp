#include <iostream.h>

int main()
{ 
    int n;
    do
    { 
        cout << "Въведете стойност за n (n >= 0): ";
        cin >> n;
    } while(n < 0);

    cout << "Въведете реално число: ";
    double x; cin >> x;
    if(n == 0)
    {
        cout << "H0(" << x << ")= " << 1 << endl;
    }
    else if(n == 1)
    {
        cout << "H1(" << x << ")= " << x << endl;
    }
    else
    { 
        double t0 = 1, t1 = x, t;
        for(int i = 2; i <= n; i++)
        { 
            t = 2*x*t1 - t0;
            t0 = t1;
            t1 = t;
        }
        cout << "H" << n << "(" << x << ")= " << t << endl;
    }
    return 0;
}
