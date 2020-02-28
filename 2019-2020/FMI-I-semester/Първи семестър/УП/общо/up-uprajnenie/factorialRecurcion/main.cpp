#include <iostream>

using namespace std;

unsigned long long factorial(int n)
{
    //opredelqne na dunoto
    if(n==0)
        return 1;

    return n*factorial(n-1);

}

unsigned long long factorialInter(int n)
{
    int result=1;
    //zadelq po malko pamet!!!!
    for(int i=n ; i>1; i--)
        result*=i;

        return result;

}
int main()
{
    cout << factorial(42) << endl;
    cout << factorialInter(3) << endl;
    return 0;
}
