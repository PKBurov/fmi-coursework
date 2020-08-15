unsigned int conv(unsigned int x, char* num)
{
    if(x == 0) 
        return 0;
    int pos = conv(x/10, num);
    num[pos] = x%10 + '0';
    num[pos+1] = '\0';
    return pos+1;
}
