double Hermite(double x, int n)
{
    if(n == 0) 
        return 1;
    if(n == 1) 
        return 2*x;
    return 2*x*Hermite(x, n-1) - 2*(n-1)*Hermite(x, n-2);
}

