#include <string.h>

char* strdup(const char* str1, char* str2)
{ 
    size_t len = strlen(str1)+1;
    str2 = new char[len];
    if(!str2)
    {
        return NULL;
    }

    while(*str2++ = *str1++)
        ;
    return str2 - len;
}
