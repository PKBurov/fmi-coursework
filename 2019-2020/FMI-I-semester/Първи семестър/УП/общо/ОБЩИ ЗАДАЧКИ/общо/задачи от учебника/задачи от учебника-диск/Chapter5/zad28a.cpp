int max(int n, int a[])
{ 
    if(n == 1) 
        return a[0];

    int x = max(n-1, a);
    if(x < a[n-1])
        return a[n-1];
    return x;
}
