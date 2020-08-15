double mult(double a[], int n, int i, int fact)
{
    if(i == n) return 1;

    double mul = mult(a, n, i+1, fact*(i+1));
    if(2 < a[i] && a[i] < fact)
    {
        return mul*a[i];
    }
    else
    {
        return mul;
    }
}

double reciprocal(double a[], int n)
{
    return 1/mult(a, n, 0, 1);
}
