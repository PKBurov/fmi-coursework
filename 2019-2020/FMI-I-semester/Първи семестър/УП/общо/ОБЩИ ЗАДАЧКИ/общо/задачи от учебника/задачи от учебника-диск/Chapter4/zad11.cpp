#include <iostream.h>

double help_func(double a, double b, double c, double x)
{
    return a*x*x*x/3 + b*x*x/2 + c*x;
}

int main()
{ 
    cout << "Въведете стойности на коефициентите (a, b, c): ";
    double a, b, c;
    cin >> a >> b >> c;

    cout << "Въведете интервала (p q): ";
    double p, q;
    cin >> p >> q;

    double area = help_func(a, b, c, q) -
                  help_func(a, b, c, p);
    cout << "Площта на фигурата между: "
         << a << "x*x + " << b << "x + " << c
         << ", абсцисната ос и правите x = " << p
         << " и x = " << q << " е: " << area << endl;
    return 0;
}
