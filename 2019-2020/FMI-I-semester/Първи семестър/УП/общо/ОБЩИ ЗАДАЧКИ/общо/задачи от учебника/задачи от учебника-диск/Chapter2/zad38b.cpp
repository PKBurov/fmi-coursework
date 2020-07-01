#include <iostream.h>
#include <math.h>

int main() 
{
    cout << "Въведете стойности за x и n (n>=1):";
    double x; 
    cin >> x;
    int n;
    cin >> n;

    double y = sin(x), 
           s = y, c = y;
    for(int i = 2; i <= n; i++)
    { 
        y = y*c;
        s = s + y;
    }
    cout << "s= " << s << endl;
    return 0;
}
