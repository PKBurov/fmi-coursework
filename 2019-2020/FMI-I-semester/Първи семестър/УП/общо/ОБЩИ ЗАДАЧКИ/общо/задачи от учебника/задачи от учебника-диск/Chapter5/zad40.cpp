#include <iostream.h>

void pyramid(char currentChar, int currentRow,
             int countChars, char maxChar)
{ 
    if(currentChar == maxChar)
    {
        cout << currentChar;
    }
    else if(countChars == currentRow - 1)
    {
        cout << currentChar << '\n';
        // Буквите, с които започват редовете са последователни.
        // След първата буква на предходния ред са
        // изведени countChars букви.
        // Последната буква на текущия ред не е преброена.
        pyramid(currentChar - countChars + 1, currentRow + 1, 0, maxChar);
    }
    else
    {
        cout << currentChar << " ";
        pyramid(currentChar + 1, currentRow, countChars + 1, maxChar);
    }
}

void drawPyramid(char maxChar)
{
    if(maxChar < 'A' || maxChar > 'Z') 
        return;
    pyramid('A', 1, 0, maxChar);
}
