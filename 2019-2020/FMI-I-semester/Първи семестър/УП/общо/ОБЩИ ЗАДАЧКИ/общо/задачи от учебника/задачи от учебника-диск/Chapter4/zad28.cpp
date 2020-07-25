#include <iostream.h>
#include <string.h>

int log2(int x)
{ 
    int y = 2,
        z = 0;
    while(y <= x)
    { 
        y *= 2;
        z++;
    }
    return z;
}

char* toBinary(int x)
{ 
    // определяне на броя на цифрите в двоичния запис на x
    char * s = new char[log2(x)+2];
    char   tmp = 0;
    int i = 0,
        c = 0;

    // намиране на двоичния запис на x в обратен ред
    while(x != 0)
    {
        s[i] = '0' + x % 2;
        x /= 2;
        i++;
    }
    s[i] = '\0';
    // обръщане на двоичния запис на x
    for(c = 0; c < i/2; c++)
    { 
        tmp = s[c];
        s[c] = s[i-c-1];
        s[i-c-1] = tmp;
    }
    return s;
}
