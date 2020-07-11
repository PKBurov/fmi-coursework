#include <iostream.h>
const int MAX_SIZE = 11;

int main()
{
    // десетично число, което ще бъде преобразувано
    // в осмична бройна система
    unsigned int number;
    cout << "number= ";
    cin >> number;
    // помощен масив, в който ще се записват остатъците
    unsigned int temp[MAX_SIZE];
    unsigned int count = 0;

    if(number == 0)
    {
        cout << number << endl;
    }
    else
    {
        while(number)
        { 
            temp[count] = number % 8;
            count++;
            number /= 8;
        }

        // извеждане на елементите на масива 
        // с остатъците в обратен ред
        for(int i = count-1; i >= 0; i--)
        {
            cout << temp[i];
        }
    }
    cout << endl;
    return 0;
}
