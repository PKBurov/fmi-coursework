#include <iostream.h>

int main()
{
    int n, min, max;
    do
    {
        cout << "n (n>=0) ";
        cin >> n;
    } while(n < 0);

    max = min = n % 10;
    n /= 10;
    while(n)
    {
        if(n % 10 > max)
        {
            max = n % 10;
        }
        else if(n % 10 < min)
        {
            min = n % 10;
        }
        n /= 10;
    }
    cout << "Най-малката цифра е " << min << endl
         << "Най-голямата цифра е " << max << endl;
    return 0;
}
