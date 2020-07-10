#include <iostream.h>

int main()
{
    int n;
    cout << "Въведете положително цяло число!\n";
    do
    {
        cout << "n= ";
        cin >> n;
    } while(n <= 0);

    int digit;
    cout << "Въведете цифра! \n";
    do
    {
        cin >> digit;
    }
    while(digit < 0 || digit > 9);

    int newDigit;
    cout << "Нова цифра? \n";
    do
    {
        cin >> newDigit;
    }
    while(newDigit < 0 || newDigit > 9 || digit== newDigit);

    int len = 0, temp = n;
    while(temp != 0)
    { 
        len++;
        temp = temp/10;
    }

    int k = 1;
    for(int i = 1; i <= len; i++)
    { 
        if(n/k%10 == digit) 
        {
            n = (n/(k*10)*10+newDigit)*k + n%k;
        }
        k = k*10;
    }
    cout << "Резулатът от размяната е " << n << endl;
    return 0;
}
