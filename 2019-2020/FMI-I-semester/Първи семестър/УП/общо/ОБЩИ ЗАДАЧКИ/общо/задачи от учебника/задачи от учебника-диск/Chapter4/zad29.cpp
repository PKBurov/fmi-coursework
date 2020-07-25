#include <string.h>

int max(int a, int b)
{ 
    return a>=b ? a : b;
}

int maxCommonPreffix(const char* s1, const char* s2)
{ 
    int i = 0,
        n = max(strlen(s1), strlen(s2));
    while(i < n && s1[i] == s2[i])
        i++;
    return i;
}
