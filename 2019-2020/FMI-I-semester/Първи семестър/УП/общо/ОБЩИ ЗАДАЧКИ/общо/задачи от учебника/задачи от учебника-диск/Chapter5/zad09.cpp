int countDig(int n, int k)
{
    if(n == 0)
        return 0;
    return countDig(n/k, k) + 1;
}
