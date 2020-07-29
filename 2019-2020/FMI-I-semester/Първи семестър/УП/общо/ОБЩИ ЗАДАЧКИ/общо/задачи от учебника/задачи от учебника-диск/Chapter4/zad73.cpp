int funcMax(int (*f)(int),int a, int b)
{
    int maxValue = f(a);
    for(a++; a <= b; a++)
    {
        if(maxValue < f(a))
        {
            maxValue = f(a);
        }
    }
    return maxValue;
}
