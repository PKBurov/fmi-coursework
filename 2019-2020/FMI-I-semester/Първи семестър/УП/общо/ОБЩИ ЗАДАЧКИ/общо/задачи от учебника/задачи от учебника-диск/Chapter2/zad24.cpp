#include <iostream.h>

int main()
{
    cout << "Въведете код на булева стойност (0 или 1): ";
    int a; cin >> a;
    cout << "Въведете код на друга булева стойност (0 или 1): ";
    int b; cin >> b;

    // изчисляване на стойността на a nand b
    bool nand;
    if(!a && !b) 
    {
        nand = true;
    }
    else if(!a && b)
    {
        nand = true;
    }
    else if(a && !b)
    {
        nand = true; 
    }
    else 
    {
        nand = false; 
    }

    // или  if(a&&b) nand = false; else nand = true;
    // или nand = !(a&&b);
    // извеждане на стойността на nand
    cout << a << " nand " << b << " = " << nand << '\n';
    return 0;
}
