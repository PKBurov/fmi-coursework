bool fibTest(int a, int b, int x)
{
    if(x <= a)
    {
        return x == a;
    }
    return fibTest(b, a+b, x);
}

bool fibTest(int x)
{
    return fibTest(0, 1, x);
}
