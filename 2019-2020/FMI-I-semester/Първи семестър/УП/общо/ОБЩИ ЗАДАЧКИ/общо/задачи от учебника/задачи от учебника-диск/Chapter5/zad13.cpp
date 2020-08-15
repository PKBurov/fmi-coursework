int reverse(int n, int k, int m)
{ 
    if(n == 0)
    {
        return m;
    }
    return reverse(n/k, k, m*k + n % k);
}

int reverse(int n, int k)
{
    return reverse(n, k, 0);
}
