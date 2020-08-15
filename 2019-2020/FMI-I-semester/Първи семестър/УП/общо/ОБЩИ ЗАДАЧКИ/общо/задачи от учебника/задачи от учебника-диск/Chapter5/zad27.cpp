int sum(int n, int a[])
{ 
    if(n == 0) 
        return 0;

    return a[n-1] + sum(n-1, a);
}
