#include <iostream.h>
#include <math.h>

int main()
{
    double x;
    do
    {
        cout << "Въведете стойност за x (x > 1): "; 
        cin >> x;
    } while (x <= 1);

    int min = (int)ceil(x+log(x)),
        max = (int)floor(x*x+2*x+exp(x));
    for(int i = min; i <= max; i++)
    {
        cout << i << endl;
    }
    return 0;
}
