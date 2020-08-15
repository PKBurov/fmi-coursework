bool contain(int a[], int n, int number)
{
    if(n == 0) return false;

    return a[n-1] == number || contain(a, n-1, number);
}
