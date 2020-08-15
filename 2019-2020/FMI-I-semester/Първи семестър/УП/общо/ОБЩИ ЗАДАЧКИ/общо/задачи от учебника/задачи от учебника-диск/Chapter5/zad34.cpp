int strcomp(const char* str1, const char* str2)
{
    if(!*str1 || *str1 != *str2)
        return *str1 - *str2;
    return strcomp(str1+1, str2+1);
}
