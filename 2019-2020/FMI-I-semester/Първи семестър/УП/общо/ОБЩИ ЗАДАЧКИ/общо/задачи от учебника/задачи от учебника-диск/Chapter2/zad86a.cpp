#include <iostream.h>

int main()
{
    for(char i = 'A'; i <= 'E'; i++)
    { 
        for(char j = i; j <= i+4; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
