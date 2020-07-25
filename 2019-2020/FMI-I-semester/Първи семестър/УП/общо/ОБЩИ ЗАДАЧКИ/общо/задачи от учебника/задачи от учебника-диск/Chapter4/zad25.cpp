#include <iostream.h>
#include <math.h>
const int MAX_LEN = 100;

char* num2str(unsigned int num)
{
    int len = (int)log10((double)num) + 1;
    char * str = new char[len+1];
    if(!str)
    {
        return NULL;
    }
    str[len] = '\0';
    while (--len >= 0)
    { 
        str[len] = num%10 + '0';
        num /= 10;
    }
    return str;
}
