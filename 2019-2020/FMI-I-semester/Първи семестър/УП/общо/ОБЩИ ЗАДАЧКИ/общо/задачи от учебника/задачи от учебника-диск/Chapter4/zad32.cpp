#include <iostream.h>

char* substring(const char* text, char* substr,
                unsigned int start, unsigned int len)
{
    unsigned int i, j;
    for(i = 0; i < start && text[i]; i++);
    {
        if(i < start)
        {
            return NULL;
        }
    }

    for(j = 0; j < len && text[i+j]; j++)
    {
        substr[j] = text[i+j];
    }
    substr[j] = '\0';
    return substr;
}
