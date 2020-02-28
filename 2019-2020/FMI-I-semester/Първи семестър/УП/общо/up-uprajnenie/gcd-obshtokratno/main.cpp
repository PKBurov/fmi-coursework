#include <iostream>

using namespace std;


int gcd(int a, int b)
{
    //problem
if(a==b) return a;
else
    {
    if(a>b)
        return gcd(a-b,b);
    else
        return gcd(a,b-a);
    }
}
int main()
{
    cout << gcd(2,1) << endl;
    return 0;
}
