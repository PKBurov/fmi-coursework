#include <iostream.h>
#include <math.h>

int main()
{
    cout << "Въведете положителна реална стойност за x: ";
    double x;
    cin >> x;

    // намиране на стойността на f
    double f = (sin(sin(sin(x))) + cos(cos(cos(x)))) /
               (log(fabs(x)) + fabs(cos(x)) + exp(x));

    // извеждане на f
    cout << "f= " << f << endl;
    return 0;
}
