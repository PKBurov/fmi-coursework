#include <string.h>

void merge(const char* str1, const char* str2, char* result)
{ 
    if(!*str1)
    {
        strcpy(result, str2);
    }
    else if(!*str2)
    {
        strcpy(result, str1);
    }
    else if(*str1 < *str2)
    { 
        *result = *str1;
        merge(str1+1, str2, result+1);
    }
    else
    { 
        *result = *str2;
        merge(str1, str2+1, result+1);
    }
}
