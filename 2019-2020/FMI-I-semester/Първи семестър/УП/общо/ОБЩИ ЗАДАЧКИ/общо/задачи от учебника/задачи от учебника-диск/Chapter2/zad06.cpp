#include <iostream.h> 

int main() 
{
    cout << "Въведете стойности на реалните "
            "променливи x, y, z: ";
    double x, y, z;
    cin >> x >> y >> z;
    cout << x << " " << y << " " << z << endl;

    if(x > y)
    {
        double m = x;
        x = y;
        y = m;
    }

    if(x > z)
    {
        double m = x;
        x = z;
        z = m;
    }

    if(y > z)
    {
        double m = y;
        y = z;
        z = m;
    }

    cout << x << " " << y << " " << z << endl;
    return 0;
}
