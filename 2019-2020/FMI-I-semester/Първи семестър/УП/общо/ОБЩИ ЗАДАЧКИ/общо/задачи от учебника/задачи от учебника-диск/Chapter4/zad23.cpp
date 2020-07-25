int strcmp1(const char* str1, const char* str2)
{
    int i;
    for(i = 0; str1[i] != '\0'; i++)
    {
        if(str1[i] != str2[i])
            break;
    }
    return str1[i] - str2[i];
}

int strcmp2(const char* str1, const char* str2)
{ 
    while(*str1 && *str1 == *str2)
        ++str1, ++str2;
    return *str1 - *str2;
}
