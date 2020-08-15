int replace(int n)
{
    if(n == 0) return 0;

    int last_digit = n % 10;
    if(last_digit == 5)
    {
        return replace(n/10)*10 + 8;
    }
    else
    {
        return replace(n/10)*10 + last_digit;
    }
}
