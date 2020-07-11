#include <iostream.h>
const int MAX_SIZE = 11;

int main()
{
    cout << "Въведете стойност на степента n - "
            "цяло число от 0 до " << MAX_SIZE-1 << ": ";
    int n;
    cin >> n;
    double a[MAX_SIZE];

    // Въвеждане на коефициентите на полинома Pn
    int i;
    for(i = 0; i <= n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    cout << "Въведете стойност на степента m - "
            "цяло число от 0 до " << MAX_SIZE - 1 << ": ";
    int m;
    cin >> m;
    double b[MAX_SIZE];

    // Въвеждане на коефициентите на полинома Qn
    for(i = 0; i <= m; i++)
    { 
        cout << "b[" << i << "]= ";
        cin >> b[i];
    }

    // Намиране на сумата на полиномите P и Q
    int k;                // степен на полинома P+Q
    double r[MAX_SIZE];	  // коефициенти на полинома P+Q
    if(n >= m)
    {
        for(i = 0; i <= m; i++)
        {
            r[i] = a[i] + b[i];
        }
        for(i = m+1; i <= n; i++)
        {
            r[i] = a[i];
        }
        k = n;
        if(n == m && r[k] == 0)
        {
            while(r[k] == 0 && k != 0)
            {
                k--;
            }
        }
    }
    else
    { 
        for(i = 0; i <= n; i++)
        {
            r[i] = a[i] + b[i];
        }
        for(i = n+1; i <= m; i++)
        {
            r[i] = b[i];
        }
        k = m;
    }

    for(i = k; i >= 0; i--)
    { 
        if(i == k) 
        {
            cout << r[i] << ".x^" << i;
        }
        else if(r[i] > 0)
        {
            cout << " + " << r[i] << ".x^" << i;
        }
        else if(r[i] < 0)
        {
            cout << " - " << -r[i] << ".x^" << i;
        }
    }
    cout << endl;
    return 0;
}
