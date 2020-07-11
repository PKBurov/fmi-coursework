#include <iostream.h>

int main()
{
    int k = -1;
    for(char i = 'A'; i <= 'E'; i++)
    {
        k++;
        for(char j = i; j <= i+k; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
