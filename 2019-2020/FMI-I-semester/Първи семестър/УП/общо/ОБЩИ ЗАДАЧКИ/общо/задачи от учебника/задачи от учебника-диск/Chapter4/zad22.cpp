char* strcpy1(char* strDest, const char* strSrc)
{ 
    int i;
    for(i = 0; strSrc[i] != '\0'; i++)
    {
        strDest[i] = strSrc[i];
    }
    strDest[i] = '\0';
    return strDest;
}

char* strcpy2(char* strDest, const char* strSrc)
{ 
    unsigned int i = 0;
    while(strDest[i] = strSrc[i++])
        ;
    return strDest;
}

char* strcpy3(char* strDest, const char* strSrc)
{ 
    char* s = strDest;
    while (*strDest++ = *strSrc++)
        ;
    return s;
}
