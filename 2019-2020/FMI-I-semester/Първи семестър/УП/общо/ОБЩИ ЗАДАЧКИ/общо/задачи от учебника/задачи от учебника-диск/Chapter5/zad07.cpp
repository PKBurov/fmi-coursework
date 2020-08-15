int f_k(int n, int k)
{
    if(n == 1) 
        return 1;

    if(n % k == 1) 
        return n*f_k(n-k, k);
    return f_k(n-1, k);
}
