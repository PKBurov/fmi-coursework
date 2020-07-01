#include <iostream.h>
#include <math.h>

int main()
{
    cout << "Въведете страните на триъгълника: ";
    double a, b, c;
    cin >> a >> b >> c;

    if(a > 0 && b > 0 && c > 0 && a+b > c && a+c > b && b+c > a)
    {
        double p = (a+b+c)/2;
        double s = sqrt(p*(p-a)*(p-b)*(p-c));

        double Ha, Hb, Hc;
        Ha = (2*s)/a;  
        Hb = (2*s)/b;  
        Hc = (2*s)/c;
        cout << "Ha= " << Ha << endl
             << "Hb= " << Hb << endl
             << "Hc= " << Hc << endl;

        double Ma, Mb, Mc;
        Ma = sqrt(2*b*b + 2*c*c - a*a)/2;
        Mb = sqrt(2*a*a + 2*c*c - b*b)/2;
        Mc = sqrt(2*a*a + 2*b*b - c*c)/2;
        cout << "Ma= " << Ma << endl
             << "Mb= " << Mb << endl
             << "Mc= " << Mc << endl;

        double La, Lb, Lc;
        La = 2*sqrt(b*c*p*(p-a))/(b+c);
        Lb = 2*sqrt(a*c*p*(p-b))/(a+c);
        Lc = 2*sqrt(a*b*p*(p-c))/(a+b); 
        cout << "La= " << La << endl
             << "Lb= " << Lb << endl
             << "Lc= " << Lc << endl;
    }
    else
    {
        cout << a << ", " << b << ", "
             << c << " не са страни на триъгълник. \n";
    }
    return 0;
}
