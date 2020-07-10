#include <iostream.h>

int main()
{
    int n;
    do
    {
        cout << "Въведи n (n>1): ";
        cin >> n;
    } while(n <= 1);

    bool first = true;	// За да се изведе '.' само веднъж
    int i = 2;

    while(i < n)
    { 
        if(n % i == 0)
        {
            if(!first)
            {
                cout << ".";
            }
            cout << i;
            first = false;
            n /= i;
            if(n == 1)
            {
                break;
            }
        }
        else
        {
            i++;
        }
    }
    if(first)
    {
        cout << n;
    }
    else if(n != 1)
    {
        cout << "." << n;
    }
    cout << endl;
    return 0;
}
