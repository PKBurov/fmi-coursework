void DeleteElem(int x, int &n, int a[], bool &fl)
{
    if(n!=0)
    { 
        if(x == a[n-1])
        { 
            fl = true;
            n--;
        }
        else
        {
            int p = n-1;
            DeleteElem(x, p, a, fl);
            if(fl)
            { 
                a[p] = a[p+1];
                n--;
            }
        }
    }
}

void DeleteElem(int x, int &n, int a[])
{
    bool fl = false;
    DeleteElem(x, n, a, fl);
}
