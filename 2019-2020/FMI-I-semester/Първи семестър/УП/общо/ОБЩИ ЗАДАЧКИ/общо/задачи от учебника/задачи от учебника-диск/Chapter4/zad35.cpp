#include <math.h>

void RealToString(char* buffer, double number, int maxDigits)
{ 
    int negative = 0;
    int count = 0;
    char* current = buffer;

    if(number < 0)
    {
        number = -number;
        count = 1;
        negative = 1;
    }

    int num = (int)number;
    int digitCount = (int)log10((double)num) + 1;
    count += digitCount;

    // знака
    if(negative)
    {
        *(current++) = '-';
    }

    // ц€лата част
    int digitDivisor = (int)pow(10.0, digitCount - 1);
    while(digitDivisor)
    {
        *(current++) = (num / digitDivisor) + '0';
        num %= digitDivisor;
        digitDivisor /= 10;
    }

    // дробната част
    number -= (double)(int)number;
    if(number > 0)
    {
        // —лага се '.' само ако има дробна част
        *(current++) = '.';
        while((maxDigits--) && (number > 0))
        {
            number *= 10;
            *(current++) = (int)number + '0';
            number -= (double)(int)number;
        }
    }
    *current = '\0';
}

