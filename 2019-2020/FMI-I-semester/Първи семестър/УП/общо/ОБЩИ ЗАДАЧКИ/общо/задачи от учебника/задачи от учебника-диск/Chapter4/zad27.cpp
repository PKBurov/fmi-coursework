void replace(char* s, int n, char x, char y)
{
    n--;
    while(n >= 0)
    {
        if(s[n] == x)
        {
            s[n] = y;
        }
        n--;
    }
}
