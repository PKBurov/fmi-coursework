#include <iostream.h>

int main()
{
    int k;
    do
    {
        cout << "Въведете естествено число: ";
        cin >> k;
    } while(k < 1);

    if(k == 2)
    {
        cout << k << " е просто.\n";
    }
    else if(k == 1 || k%2 == 0)
    {
        cout << k << " не е просто.\n";
    }
    else
    {
        bool flag = true;
        for(int i = 3; i <= k/2 && flag; i = i+2)
        {
            if (k%i == 0) 
            {
                flag = false;
            }
        }
        if(flag)
        {
            cout << k << " е просто.\n";
        }
        else
        {
            cout << k << " не е просто.\n";
        }
    }
    return 0;
}
