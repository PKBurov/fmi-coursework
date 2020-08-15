int max(int p, int q, int a[])
{
    if(p == q) 
        return a[p];

    int u, v;
    int m = (p+q)/2;
    u = max(p, m, a);
    v = max(m+1, q, a);

    if(u > v)
        return u;

    return v;
}	
