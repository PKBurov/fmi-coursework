#include <iostream.h>

void pyramid(int currentNumber, int currentRow, int maxNumber)
{
    if(currentNumber == currentRow && currentRow == maxNumber)
    {
        cout << currentNumber;
    }
    else 
    {
        if(currentNumber == currentRow)
        {
            cout << currentNumber << '\n';
            pyramid(1, currentRow + 1, maxNumber);
        }
        else
        {
            cout << currentNumber << " ";
            pyramid(currentNumber + 1, currentRow, maxNumber);
        }
    }
}

void drawPyramid(int maxNumber)
{
    if (maxNumber <= 0) 
        return;

    pyramid(1, 1, maxNumber);
}
