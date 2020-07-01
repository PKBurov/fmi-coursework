#include <iostream.h>
#include <math.h>

const double PI = 3.14159265;

int main()
{
    double a, b;
    double alpha;

    // въвеждане на стойност на страната а, a > 0
    do
    {
        cout << "Въведете положителна стойност за a! \n";
        cout << "a= ";
        cin >> a;
    } while(a <= 0);

    // въвеждане на стойност на страната b, b > 0
    do
    {
        cout << "Въведете положителна стойност за b!\n";
        cout << "b= ";
        cin >> b;
    } while(b <= 0);

    // въвеждане стойността на ъгъла alpha в градуси
    do
    {
        cout << "Въведете ъгъла alpha в граници (0, 180)!\n";
        cout << "alpha= ";
        cin >> alpha;
    } while(alpha <= 0 || alpha >= 180);

    // аргументът на sin е в радиани, затова alpha
    // трябва да се преобразува в радиани
    alpha = PI/180*alpha;

    // Помощна променлива, в която ще бъде пресметнато лицето
    double s = 0;
    s = (a * b * sin(alpha)) / 2;
    cout << "Лицето на тригълника е " << s << endl;
    return 0;
}
