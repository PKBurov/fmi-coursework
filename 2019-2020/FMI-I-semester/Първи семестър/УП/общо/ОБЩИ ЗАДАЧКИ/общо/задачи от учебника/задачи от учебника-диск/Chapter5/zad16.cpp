int maxSuf(int a, int b)
{ 
    if(a % 10 != b % 10 || a == 0)
    {
        return 0;
    }
    return a%10 + 10*maxSuf(a/10, b/10);
}
