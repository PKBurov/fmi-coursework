#include <iostream.h>

int main()
{ 
    int x,
        count = 0;
    do
    { 
        cout << "Въведете положително цяло число ";
        cin >> x;
    } while(x <= 0);
    while(x > 0)
    {
        x /= 10;
        count++;
    }
    cout << "Броят на цифрите е " << count << "\n";
    return 0;
}
