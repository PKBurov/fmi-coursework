#include <iostream.h>
#include <iomanip.h>

void pyramid(int currentNumber, int currentRow, 
             int countNumbers, int maxNumber)
{
    if(currentRow == 1)
    {
        cout << setw(maxNumber);
    }

    // броят на елементите във всеки ред е 2*номера на реда - 1
    if(countNumbers == 2*(currentRow - 1) && currentRow == maxNumber)
    {
        // извеждане на последното число
        cout << currentNumber << " ";
    }
    else
    { 
        if(countNumbers == 2*(currentRow - 1))
        { 
            cout << currentNumber << '\n';
            cout << setw(maxNumber - currentRow);
            pyramid(1, currentRow + 1, 0, maxNumber);
        }
        else
        { 
            // числата след първите currentRow, 
            // трябва да се извеждат в обратен ред
            if(countNumbers < currentRow - 1)
            { 
                cout << currentNumber;
                pyramid(currentNumber + 1, currentRow, countNumbers + 1, maxNumber);
            }
            else
            { 
                cout << currentNumber;
                pyramid(currentNumber - 1, currentRow, countNumbers + 1, maxNumber);
            }
        }
    }
}

void drawPyramid(int maxNumber)
{
    if(maxNumber <= 0) 
        return;
    pyramid(1, 1, 0, maxNumber);
}

