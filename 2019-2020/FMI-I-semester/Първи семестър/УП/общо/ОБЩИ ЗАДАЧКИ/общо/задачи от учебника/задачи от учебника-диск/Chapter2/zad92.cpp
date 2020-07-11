#include <iostream.h>

int main()
{
    int number;
    cout << "Въведете положително цяло число.\n";

    do
    {
        cout << "number= ";
        cin >> number;
    } while(number <= 0);

    bool found = false;
    int lastDigit;
    while(number && !found)
    {
        // последната цифра на числото
        lastDigit = number % 10;
        // числото, без последната цифра
        int restNumber = number / 10;

        // проверка дали последната цифра се среща в
        // останалата част от числото
        while(restNumber && !found)
        {
            if(lastDigit == restNumber % 10)
            {
                found = true;
            }
            restNumber /= 10;
        }
        number = number / 10;
    }

    if(found)
    {
        cout << "Числото съдържа повтарящи се цифри "
                "и една такава е " << lastDigit << endl;
    }
    else
    {
        cout << "Числото не съдържа повтарящи се цифри.\n";
    }
    return 0;
}
