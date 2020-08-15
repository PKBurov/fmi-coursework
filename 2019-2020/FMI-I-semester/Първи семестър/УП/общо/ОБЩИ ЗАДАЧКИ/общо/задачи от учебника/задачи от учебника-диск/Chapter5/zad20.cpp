#include <iostream.h>
#include <math.h>

int log(int a, int b)
{
    if(b < a) 
        return 0;

    return log(a, b/a) + 1;
}

int main()
{
    int a;
    do
    {
        cout << "a= "; cin >> a;
    }while (a <= 1);
    int b;
    do
    {
        cout << "b= "; cin >> b;
    }while (b <= 0);

    cout << log(a, b) << endl;
    cout << (int)(log(b)/log(a)) << endl;
    return 0;
}
