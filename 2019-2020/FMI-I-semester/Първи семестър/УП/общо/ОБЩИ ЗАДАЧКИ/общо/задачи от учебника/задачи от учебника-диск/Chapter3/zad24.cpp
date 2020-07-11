#include <iostream.h>
const int MAX_SIZE = 11;

int main()
{ 
    cout << "Въведете стойност на степента n – "
            "цяло число от 0 до " << MAX_SIZE - 1 << ": ";
    int n;
    cin >> n;
    double a[MAX_SIZE];

    // Въвеждане на коефициентите на полинома P
    int i;
    for(i = 0; i <= n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    cout << "Въведете стойност на степента m – "
            "цяло число от 0 до " << MAX_SIZE - 1 << ": ";
    int m;
    cin >> m;
    double b[MAX_SIZE];

    // Въвеждане на коефициентите на полинома Q
    for(i = 0; i <= m; i++)
    {
        cout << "b[" << i << "]= ";
        cin >> b[i];
    }

    // Намиране на произведението на полиномите P и Q
    int k = n+m;    // степен на полинома P*Q

    // коефициенти на полинома P*Q
    double r[MAX_SIZE+MAX_SIZE-1];  
    for(int l = 0; l <= k; l++)
    {
        r[l] = 0;
        for(i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i+j == l) 
                {
                    r[l] = r[l] + a[i] * b[j];
                }
            }
        }
    }

    // извеждане на произведението на полиномите
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
