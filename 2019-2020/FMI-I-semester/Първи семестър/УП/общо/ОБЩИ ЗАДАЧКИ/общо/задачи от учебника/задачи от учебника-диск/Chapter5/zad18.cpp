
int sumDivs(int x, int n)
{
    if(n < 2)
    {
        return 0;
    }
    return (x%n == 0 ? n : 0) + sumDivs(x, n-1);
}
