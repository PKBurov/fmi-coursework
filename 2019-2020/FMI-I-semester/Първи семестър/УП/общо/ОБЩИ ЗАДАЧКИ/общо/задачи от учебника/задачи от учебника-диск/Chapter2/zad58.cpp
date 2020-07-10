#include <iostream.h>

int main()
{ 
    int number;
    do
    { 
        cout << "Въведете положително цяло число "
             << "с четен брой цифри! \n";
        cout << "number= "; 
        cin >> number;
    } while(number <= 0);

    // намиране на броя и сумата на цифрите на числото
    int countDigits = 0;
    int digitsSum = 0;

    // копие на числото, тъй като то ще бъде разрушено
    // при намиране на броя на цифрите
    int copyNumber = number;
    while(copyNumber)
    { 
        digitsSum += copyNumber % 10;
        copyNumber /= 10;
        countDigits++;
    }
    if(countDigits % 2 == 0)
    { 
        // числото има четен брой цифри
        copyNumber = number;

        // намиране на сумата на младшите countDigits/2 цифри
        int halfDigitsSum = 0;
        for(int i = 0; i <= countDigits/2 - 1; i++)
        {
            halfDigitsSum += copyNumber % 10;
            copyNumber /= 10;
        }
        if(halfDigitsSum*2 == digitsSum)
        {
            cout << "Числото притежава свойството! \n";
        }
        else 
        {
            cout << "Числото не притежава свойството! \n";
        }
    }
    else
    {
        cout << "Числото има нечетен брой цифри!\n";
    }
    return 0;
}
