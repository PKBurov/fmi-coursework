#include <iostream.h>
const int MAX_SIZE = 20;

// Дефиниране на процедура за въвеждане
// на коефициентите на полином
void ReadPolynomial(int p, double d[])
{
    for(int i = 0; i < p; i++)
    { 
        cout << i << "-и коефициент: ";
        cin >> d[i];
    }
}

// Дефиниране на процедура за извеждане на полином
void WritePolynomial(int p, double d[])
{
    for(int i = 0; i < p; i++)
    {
        if(d[i] != 0)
        {
            if(d[i] > 0 && i != 0) 
            { 
                cout << "+" << d[i] << ".x^" << p-i-1;
            }
        }
        else 
        {
            cout << d[i] << ".x^" << p-i-1;
        }
        cout << endl;
    }
}

// Дефиниране на процедура за намиране
// стойност на полином
double Polynomial(int p, double d[], double x)
{ 
    double s = d[0];
    for(int i = 1; i < p; i++)
    {
        s = s*x + d[i];
    }
    return s;
}

int main() 
{
    cout << "Въведете стойност на n от интервала [1, "
         << MAX_SIZE << "]: ";
    int n; 
    cin >> n;

    cout << "Въведете коефициентите на полинома P.\n";
    double a[MAX_SIZE]; 
    ReadPolynomial(n, a);

    cout << "Въведете стойност на m от интервала [1, "
         << MAX_SIZE << "]: ";
    int m; 
    cin >> m;

    cout << "Въведете коефициентите на полинома Q.\n";
    double b[MAX_SIZE]; 
    ReadPolynomial(m, b);

    cout << "Въведете стойност на k от интервала [1, "
         << MAX_SIZE << "]: ";
    int k; 
    cin >> k;

    cout << "Въведете коефициентите на полинома R.\n";
    double c[MAX_SIZE]; 
    ReadPolynomial(k, c);

    cout << "x= ";
    double x; 
    cin >> x;

    cout << "Стойността на полинома \n";
    WritePolynomial(n, a);
    cout << "за x " << x << " е: " 
         << Polynomial(n, a, x) << endl;

    cout << "Стойността на полинома \n";
    WritePolynomial(m, b);
    cout << "за x " << x << " е: "
         << Polynomial(m, b, x) << endl;

    cout << " Стойността на полинома \n";
    WritePolynomial(k, c);
    cout << "за x " << x << " е: "
         << Polynomial(k, c, x) << endl;

    return 0;
}
