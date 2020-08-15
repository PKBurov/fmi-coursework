double Pol(int n, double a[], double x)
{
    if(n == 0) return a[0];

    return Pol(n-1, a, x) * x + a[n];
}
