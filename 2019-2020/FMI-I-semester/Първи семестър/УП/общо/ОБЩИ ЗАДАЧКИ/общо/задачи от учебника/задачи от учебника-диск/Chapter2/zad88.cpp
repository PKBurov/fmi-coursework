#include <iostream.h>

int main()
{
    int a, b;
    do
    {
        cout << "a= ";
        cin >> a;
        cout << "b= ";
        cin >> b;
    } while(a > b || a < 0);

    for(int i = a; i <= b; i++)
    {
        // d пази последната цифра на i,
        // si – останалата част от i
        int d = i % 10;
        int si = i / 10;
        while(si && d >= si % 10)
        {
            d = si % 10;  // намира последната цифра
            si /= 10;     // и я премахва
        }

        if(!si)	  // не са намерени цифри в неправилен ред
        {
            cout << i << " ";
        }
    }
    return 0;
} 
