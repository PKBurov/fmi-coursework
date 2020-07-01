#include <iostream.h>
const double PI = 3.14159265;

int main()
{
    double alpha;

    // въвеждане на стойност за alpha в градуси
    cout << "alpha= ";
    cin >> alpha;
    double alphaRadian;
    alphaRadian = PI/180*alpha;
    cout << alpha << " градуса са равни на "
         << alphaRadian << " радиана.";
    return 0;
}
