#include <iostream.h>
// дефиниране на реална функция, която
// намира лице на кръг с даден радиус

double CircleArea(double r)
{
    const double PI = 3.14159265;
    return PI*r*r;
}

int main()
{
    cout << "Радиус на кръга (реално неотрицателно число)? ";
    double Radius; cin >> Radius;
    cout << "Площта на кръга с радиус "
         << Radius << " е " << CircleArea(Radius) << endl;
    return 0;
}
