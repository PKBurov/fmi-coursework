#include <iostream.h>
#include <math.h>

int main()
{
    double a, b, c;
    cout << "a= ";
    cin >> a;
    cout << "b= ";
    cin >> b;
    cout << "c= ";
    cin >> c;

    // помощна променлива, в която се намира
    // средно квадратичното на 3-те числа
    double sqAvarage = sqrt((a*a + b*b + c*c)/3);
    cout << "Средно квадратичното на трите числа е "
         << sqAvarage << endl;
    return 0;
}
