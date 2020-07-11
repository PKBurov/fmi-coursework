#include <iostream.h>
#include <math.h>

int main() 
{ 
    cout << "Въведете стойност за R (R>0): ";
    double R; 
    cin >> R;
    for(int x = (int)ceil(-R); x <= (int)R; x++)
    {
        for(int y = (int)ceil(-R); y <= (int)R; y++)
        {
            if(x*x + y*y <= R*R)
            {
                cout << "(" << x << ", " << y << ")\n";
            }
        }
    }
    return 0;
}
