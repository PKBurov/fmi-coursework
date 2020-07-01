#include <iostream.h>

int main()
{
    cout << "Въведете седем положителни реални стойности за "
         << " (m, n, p, q, r, s, t):";
    double m, n, p, q, r, s, t;
    cin >> m >> n >> p >> q >> r >> s >> t;

    // намиране на стойността на f
    double f = m + n / (p + q / (r + s / t));

    // извеждане на f
    cout << "f= " << f << endl;
    return 0;
}
