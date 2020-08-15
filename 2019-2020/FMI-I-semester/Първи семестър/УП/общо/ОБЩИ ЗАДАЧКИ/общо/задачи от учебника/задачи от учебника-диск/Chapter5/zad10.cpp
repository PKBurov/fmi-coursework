int sumDig(int n, int k)
{
    if(n == 0)
        return 0;
    return sumDig(n/k, k) + n%k;
}
