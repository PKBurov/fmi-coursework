#include <iostream.h>
#include <math.h>

int main()
{
    int number;
    cout << "Въведете цяло число: ";
    cin >> number;
    bool negative = number < 0;

    // обръщане на цифрите на модула на числото
    number = abs(number);
    int symNumber = 0, temp = number;
    while(temp)
    { 
        symNumber = symNumber*10 + temp%10;
        temp = temp / 10;
    }

    // ако въведеното число е отрицателно, знакът
    // трябва да се запази и при симетричното му число
    if(negative)
    {
        symNumber = -symNumber;
        number = -number;
    }
    cout << "Симетричното число на числото " << number 
         << " e " << symNumber << endl;
    return 0;
}
