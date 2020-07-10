#include <iostream.h>

int main()
{ 
    int x = 0,  // даденото число
        // reversed съдържа обърнатия запис на цифрите
        // на x без нечетните цифри
        reversed = 0,
        zeros = 0;  // брой нули в края на x
    do
    {
        cout << "Въведете неотрицателно цяло число: ";
        cin >> x;
    } while(x < 0);

    // намиране на нулите в края на x
    while(x != 0 && x % 10 == 0)
    { 
        zeros ++;
        x /= 10;
    }

    // натрупване на четните цифри на x в reversed
    while(x != 0)
    { 
        if(x % 10 % 2 == 0)
        {
            reversed = reversed * 10 + x % 10;
        }
        x /= 10;
    }

    // извеждане на reversed отдясно наляво
    if(reversed == 0) cout << 0 << endl; else
    {
        while(reversed != 0)
        {
            cout << reversed % 10;
            reversed /= 10;
        }

        // извеждане на нулите в края на числото
        for( ;zeros > 0; zeros--)
        {
            cout << "0";
        }
        cout << endl;
    }
    return 0;
}
