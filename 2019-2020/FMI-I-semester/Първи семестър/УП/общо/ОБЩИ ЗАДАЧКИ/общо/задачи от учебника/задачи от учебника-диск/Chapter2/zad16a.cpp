#include <iostream.h>

int main()
{
    char c;
    cout << "c= "; 
    cin >> c;
    // сравняват се ASCII кодовете на символите
    if(c >= '0' && c <= '9')
    {
        cout << "Въведеният символ е цифра.\n";
    }
    else
    {
        cout << "Въведеният символ не е цифра.\n";
    }
    return 0;
}
