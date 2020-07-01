#include <iostream.h>

int main()
{
    unsigned int i;
    cout << "i= ";
    cin >> i;

    unsigned int low, high;       // младши и старши полубайт
    low = i & 0x0F;               // използва се маската 00001111 
    high = i & 0xF0;              // използва се маската 11110000 
    high = high >> 4;             // изместване xxxx0000 до 0000xxxx 

    if(low == high)
    {
        cout << "Младшият и старшият полубайтове на "
             << i << " са равни.\n";
    }
    else
    {
        cout << "Младшият и старшият полубайтове на "
             << i << " не са равни.\n";
    }
    return 0;
}
