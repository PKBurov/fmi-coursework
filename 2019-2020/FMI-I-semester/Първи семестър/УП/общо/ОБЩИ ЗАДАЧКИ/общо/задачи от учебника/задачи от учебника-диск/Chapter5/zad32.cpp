#include <string.h>

void insert(char* str, char sym)
{ 
    if(*str && sym > *str)  
    {
        insert(str+1, sym);
        return;
    }

    // освобождаване на място за новия елемент
    // като останалите елементи се изместват с
    // една позиция надясно
    for(char* ptr = str + strlen(str); ptr >= str; ptr--)
    {
        ptr[1] = ptr[0];
    }
    *str = sym;
}
