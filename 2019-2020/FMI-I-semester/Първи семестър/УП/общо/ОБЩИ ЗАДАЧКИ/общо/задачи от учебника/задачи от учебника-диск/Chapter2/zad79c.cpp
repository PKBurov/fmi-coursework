#include <iostream.h>

int main()
{ 
    cout << "Въведете стойност за n (n>=1): ";
    int n; 
    cin >> n;
    double s = 0;
    for(int i = 1; i <= n; i++)
    {
        double y = 1;
        for(int j = 1; j <= n-i+1; j++)
        {
            y = y*(1./i);
        }
        s = s + y;
    }
    cout << "s= " << s << endl;
    return 0;
}
