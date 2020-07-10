#include <iostream.h>

int main()
{
    int c;
    do
    {
        cout << "Въведете цифра (0 - 9): ";
        cin >> c;
    } while(c < 0 || c > 9);
    int  n;
    do
    {
        cout << "Въведете неотрицателно цяло число: ";
        cin >> n;
    } while(n < 0);

    int a = n;
    while(a != 0 && a%10 != c) 
    {
        a = a/10;
    }
    if(a != 0 || (n == 0 && c == 0))
    {
        cout << c << "  се съдържа в " << n << endl;
    }
    else
    {
        cout << c << " не се съдържа в " << n << endl;
    }
    return 0;
}
