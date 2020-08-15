int mult(int m, int n)
{
    if(n == 1) 
        return m;
    return mult(m, n-1) + m;
}
