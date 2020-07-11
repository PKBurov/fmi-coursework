#include <iostream.h>
#include <iomanip.h>

int main()
{
    for(int i = 1; i <= 7; i++)
    {
        cout << setw(2 * (i-1) + 1) << ' ';
        for(int j = 1; j <= 8-i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
