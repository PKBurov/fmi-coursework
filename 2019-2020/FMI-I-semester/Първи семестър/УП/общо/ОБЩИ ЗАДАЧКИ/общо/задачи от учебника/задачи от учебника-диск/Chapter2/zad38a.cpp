#include <iostream.h>
#include <math.h>

int main() 
{
    cout << "Въведете стойности за x и n (n>=1):";
    double x; 
    int n; 
    cin >> x;
    cin >> n;

    double y = x, 
           s = sin(x);
    for(int i = 2; i <= n; i++)
    {
        y = y*x;
        s = s + sin(y);
    }
    cout << "s= " << s << endl;
    return 0;
}
