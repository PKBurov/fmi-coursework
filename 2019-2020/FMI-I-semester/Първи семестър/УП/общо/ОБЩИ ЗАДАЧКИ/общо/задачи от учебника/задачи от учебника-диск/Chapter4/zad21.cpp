#include <iostream.h>
const int MAX_LEN = 100;

unsigned int strlen1(const char* str)
{ 
    unsigned int i;
    for(i = 0; str[i] != '\0'; ++i)
        ;
    return i;
}

unsigned int strlen2(const char* str)
{ 
    int i = -1;
    while(str[++i])
        ;
    return (unsigned int)i;
}

unsigned int strlen3(const char* str)
{ 
    const char* s = str;
    while(*str++)
        ;
    return (unsigned int)(str - s - 1);
}

int main()
{
    char text[MAX_LEN];
    cout << "Въведете текст: ";
    cin.getline(text, MAX_LEN);

    cout << "Len1= " << strlen1(text) << endl;
    cout << "Len2= " << strlen2(text) << endl;
    cout << "Len3= " << strlen3(text) << endl;

    return 0;
}
