int countDig(int n, int k)
{
    if(n < 10)
        return n == k;
    return (n % 10 == k) + countDig(n/10, k);
}
