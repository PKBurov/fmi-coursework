#include <iostream.h>

int main()
{ 
    unsigned int x;
    unsigned int mask = 1;

    cout << "x= ";
    cin >> x;
    while(mask != 0)
    { 
        if(x & mask)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        mask = mask << 1;
    }
    cout << endl;
    return 0;
}
