#include <iostream.h>

int main()
{ 
    int number;           // дадено число
    int sum = 0;          // натрупва сумата на въведените числа
    cout << "число? ";
    cin >> number;
    // до срещането на 0
    while(number != 0)
    { 
        sum += number;
        // въвеждане на следващо число
        cout << "число? ";
        cin >> number;
    }
    cout << "Сумата на въведените числа е " << sum << endl;
    return 0;
}
