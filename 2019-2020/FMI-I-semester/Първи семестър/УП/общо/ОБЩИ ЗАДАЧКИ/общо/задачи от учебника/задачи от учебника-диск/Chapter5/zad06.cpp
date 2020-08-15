int f3(int n)
{
    if (n == 1) 
        return 1;
    if (n % 3 == 1) 
        return n*f3(n-3);
    return f3(n-1);
}
