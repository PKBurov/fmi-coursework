#include <iostream.h>
#include <math.h>

int main()
{
    cout << "Коефициенти на квадратното уравнение: ";
    double a, b, c;
    cin >> a >> b >> c;

    if(a != 0 && b*b - 4*a*c >= 0)
    {
        double radical = sqrt(b*b - 4*a*c);
        double root1 = (-b + radical) / (2*a);
        double root2 = (-b - radical) / (2*a);
        cout << "Корените на уравнението " << a << "x^2 + " << b
             << "x + " << c << " са: " << root1 << " и " 
             << root2 << endl;
    }
    else
    {
        cout <<  a << "x^2 + " << b << "x + " << c
             << " няма реални корени.\n";
    }
    return 0;
}
