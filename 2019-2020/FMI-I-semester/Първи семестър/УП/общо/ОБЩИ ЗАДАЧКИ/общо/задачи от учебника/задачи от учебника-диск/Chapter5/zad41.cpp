#include <iostream.h>

void table(char currentChar, int currentRow,
           int countChars, char maxChar)
{
    // Броят на символите във всеки ред е maxChar-'A'+1
    // Броят на редовете трябва да е равен на броя на колоните
    if(countChars == currentRow - 1 && currentRow == maxChar - 'A' + 1)
    {
        cout << currentChar << " ";
    }
    else
    {
        if(countChars == maxChar - 'A')
        {
            cout << currentChar << '\n';
            table('A' + currentRow, currentRow + 1, 0, maxChar);
        }
        else if(currentChar < maxChar)
        { 
            cout << currentChar;
            table(currentChar + 1, currentRow, countChars + 1, maxChar);
        }
        else
        { 
            cout << currentChar;
            table('A', currentRow, countChars + 1, maxChar);
        }
    }
}

void drawTable(char maxChar)
{
    if(maxChar < 'A' || maxChar > 'Z') 
        return;
    table('A', 1, 0, maxChar);
}
