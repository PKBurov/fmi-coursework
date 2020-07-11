#include <iostream.h>
const int MAX_SIZE = 50;

int main()
{
    cout << "Въведете стойност на n – цяло число от 1 до "
         <<  MAX_SIZE << ": ";
    int n;
    cin >> n;
    double a[MAX_SIZE];

    // Въвеждане на вектора a
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    // Въвеждане на вектора b
    double b[MAX_SIZE];
    for(i = 0; i < n; i++)
    {
        cout << "b[" << i << "]= ";
        cin >> b[i];
    }

    // намиране на скаларното произведение на векторите
    double s = 0;
    for(i = 0; i < n; i++)
    {
        s = s + a[i]*b[i];
    }

    // извеждане на скаларното произведение
    cout << "Скаларното произведение на двата вектора е: "
         << s << endl;
    return 0;
}
