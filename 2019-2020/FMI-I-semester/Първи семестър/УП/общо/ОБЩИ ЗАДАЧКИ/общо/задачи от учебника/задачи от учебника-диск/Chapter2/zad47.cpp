#include <iostream.h>
#include <math.h>

int main()
{
    double y = sqrt(99);
    for(int i = 97; i >= 1; i = i-2)
    {
        y = sqrt(i + y);
    }
    cout << "y= " << y << endl;
    return 0;
}
