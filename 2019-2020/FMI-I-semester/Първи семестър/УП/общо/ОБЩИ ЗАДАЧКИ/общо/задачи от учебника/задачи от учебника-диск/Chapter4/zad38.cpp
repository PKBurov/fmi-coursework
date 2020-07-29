#include <iostream.h>
#include <string.h>

char* insertSorted(char c, char* a)
{
    int n = strlen(a);
    // заделяне на памет, необходима за елементите на a и c
    char* result = new char [n+2];
    int i = 0; // текущо разлеждан символ в символния низ a

    while(i < n && a[i] < c)
    {
        result[i] = a[i];
        i++;
    }
    result[i] = c;

    while(i < n)
    {
        result[i+1] = a[i];
        i++;
    }

    result[n+1] = '\0';
    return result;
}

int main()
{ 
    char* s = insertSorted('9',"14688");
    cout << s << endl;
    delete s;
    return 0;
}
