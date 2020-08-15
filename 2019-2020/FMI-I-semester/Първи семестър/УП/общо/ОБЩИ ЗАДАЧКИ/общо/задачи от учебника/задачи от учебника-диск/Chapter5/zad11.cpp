bool digit(int n, int k)
{
    if(n < 10) 
        return n == k;
    return (n % 10 == k) || digit(n/10, k);
}
