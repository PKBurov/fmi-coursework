#include <iostream.h>
const int MAX_SIZE = 8;

int main()
{
    // числото, което ще бъде преобразувано
    // в шестнадесетична бройна система
    unsigned int number;
    cout << "number= ";
    cin >> number;
    // помощен масив, в който ще се записват остатъците
    char temp[MAX_SIZE];
    unsigned int count = 0;

    if(number == 0)
    {
        cout << number << endl;
    }
    else
    {
        while(number)
        {
            unsigned int remainder = number % 16;
            if(remainder < 10)
            {   // записва се символът, 
                // съответстващ на остатъка
                temp[count] = remainder + '0';
            }
            else
            {   // ако remainder  е 10 => remainder % 10 == 0
                // в масива с остатъците се записва А
                // ако remainder  е 11 => remainder % 10 == 1
                // в масива с остатъците се записва B
                // максималният остатък е 15
                temp[count] = 'A' + remainder % 10;
            }
            count++;
            number /= 16;
        }

        // извеждане в обратен ред на елементите
        // на масива с остатъците
        for(int i = count-1; i >= 0; i--)
        {
            cout << temp[i];
        }
        cout << endl;
    }
    return 0;
}
