#include <iostream.h>
#include <math.h>

int main()
{ 
    cout << "d= ";
    double d; 
    cin >> d;

    cout << "v= "; 
    double v; 
    cin >> v;

    cout << "v1= ";
    double v1; 
    cin >> v1;

    cout << "v2= ";
    double v2; 
    cin >> v2;

    cout << "eps= ";
    double eps; 
    cin >> eps;

    int dist = 0;			        // движение в посока от А към В
    double y = d, s = 0, t;

    do
    { 
        if (dist == 0)
        { 
            t = y/(v+v2); 
            dist = 1;			    // движение в посока от В към А
        }
        else
        { 
			t = y/(v+v1);
            dist = 0;
        }
        y = y - t*(v1+v2);
        cout << t * v << endl;
        s = s + t * v;
    } while(fabs(y) >= eps);

    cout << "s= " << s << endl;
    return 0;
}
