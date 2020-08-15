#include <iostream.h>

void pyramid(int currentNumber, int currentRow, int maxNumber)
{
    if(currentNumber == maxNumber - currentRow + 1 && currentRow == maxNumber)
    {
        cout << currentNumber;
    }
    else
    {
        if(currentNumber == maxNumber - currentRow + 1)
        {
            cout << currentNumber << '\n';
            pyramid(maxNumber, currentRow + 1, maxNumber);
        }
        else
        {
            cout << currentNumber << " ";
            pyramid(currentNumber - 1, currentRow, maxNumber);
        }
    }
}

void drawPyramid(int maxNumber)
{ 
    if(maxNumber <= 0) 
        return;

    pyramid(maxNumber, 1, maxNumber);
}
