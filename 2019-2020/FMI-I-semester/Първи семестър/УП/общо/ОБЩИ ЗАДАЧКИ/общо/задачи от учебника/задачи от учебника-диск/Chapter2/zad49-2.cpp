#include <iostream.h>
#include <math.h>

int main()
{
    int k;
    do
    { cout << "Въведете естествено число: ";
    cin >> k;
    } while(k < 1);

    if(k == 2 || k == 3)
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
        int i = 1;
        do
        { 
            i = i+2; 
            if(k%i == 0)
            {
                flag = false;
            }
        } while(i < sqrt(k) && flag);

        if (flag)
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
