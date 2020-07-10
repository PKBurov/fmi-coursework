#include <iostream.h>

int main()
{ 
    int  x,         // даденото число
        // reversed съдържа в обратен ред записа
        // на x в 3-на п.с. без предшестващите 0
        reversed = 0,
        zeros = 0;  // брой на водещите нули

    do
    { 
        cout << "Въведете положително цяло число в 10-на п.с.: ";
        cin >> x;
    } while(x <= 0);

    // намиране броя на водещите нули
    while(x != 0 && x % 3 == 0)
    { 
        zeros++;
        x /= 3;
    }

    //oбръщане на троичния запис на x в reversed
    while(x != 0)
    { 
        reversed = reversed * 3 + x % 3;
        x /= 3;
    }
    cout << "Съответният запис в 3-ична п.с. е: ";

    // извеждане на reversed отдясно наляво
    while(reversed != 0)
    { 
        cout << reversed % 3;
        reversed /= 3;
    }

    // извеждане на водещите нули
    for(; zeros > 0; zeros--)
    {
        cout << "0";
    }
    cout << "\n";
    return 0;
}
