#include <iostream.h>
#include <math.h>

int main()
{
    int number;

    cout << "Въведете положително цяло число.\n";
    do
    {
        cout << "number= ";
        cin >> number;
    } while(number <= 0);

    int digitToBeChaged;
    cout << "Коя цифра ще бъде замененена?\n";
    do
    {
        cin >> digitToBeChaged;
    }
    while(digitToBeChaged < 0 || digitToBeChaged > 9);

    int newDigit;
    cout << "С коя цифра ще бъде заменена цифрата " 
        << digitToBeChaged << "? \n";
    do
    {
        cin >> newDigit;
    }
    while(newDigit < 0 || newDigit > 9 || digitToBeChaged == newDigit);

    // намиране на броя на нулите в края на числото
    int zerosAtEnd = 0;
    int copyNumber = number;
    while(copyNumber && copyNumber % 10 == 0)
    {
        copyNumber /= 10;
        zerosAtEnd++;
    }

    // в changedNumber ще се съдържа обърнатият резултат
    int changedNumber = 0;
    bool foundDifferent = false;
    while(number > 0)
    {
        if(number % 10 == digitToBeChaged)
        {
            changedNumber = changedNumber*10 + newDigit;
            if(number % 10 == 0 && !foundDifferent)
            {
                zerosAtEnd--;
            }
            else 
            {
                foundDifferent = true;
            }
            if(newDigit == 0 && !foundDifferent)
            {
                zerosAtEnd++;
            }
        }
        else
        { 
            changedNumber = changedNumber*10 + number % 10;
            if(number % 10)
            {
                foundDifferent = true;
            }

            // number < copyNumber означава, че това е 0,
            // различна от крайните 0-ли в числото
            if(number % 10 == 0 && !foundDifferent && number < copyNumber)
            {
                zerosAtEnd++;
            }
        }
        number = number / 10;
    }

    // генериране на резултата
    int result = 0;
    while(changedNumber > 0)
    { 
        result = result*10 + changedNumber % 10;
        changedNumber /= 10;
    }

    // добавяне на нулите накрая
    while(zerosAtEnd > 0)
    {
        result *= 10;
        zerosAtEnd --;
    }
    cout << "Резултатът е " << result << endl;
    return 0;
}
