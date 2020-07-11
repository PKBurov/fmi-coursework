#include <iostream.h>

int main()
{
    int x = 0,         // дадено число
        maxDigit = 0,  // най-често срещана цифра
        count = 0,     // брой срещания на maxDigit
        digit = 0,     // текуща цифра
        maxCount = 0,  // брой срещания на digit
        tmp = 0;       // помощна променлива

    cout << "Въведете неотрицателно цяло число: ";
    cin >> x;

    for(digit = 0; digit < 10; digit++)
    {
        count = 0;
        tmp = x;
        while(tmp != 0)
        {
            if(tmp % 10 == digit)
            {
                count++;
            }
            tmp /= 10;
        }
        if(count > maxCount)
        { 
            maxDigit = digit;
            maxCount = count;
        }
    }
    cout << maxDigit << endl;
    return 0;
}
