#include <iostream.h>
#include <iomanip.h>

int main()
{
    int i, j;
    // Извеждане на първите 4 реда
    for(i = 1; i <= 4; i++)
    {
        cout << setw(2*(i-1)+1) << ' ';
        for(j = i; j <= 4; j++)
        {
            cout << j << " ";
        }
        for(j = 4; j >= i; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    // Извеждане на последните 3 реда
    for(i=3; i >= 1; i--)
    {
        cout << setw(2*(i-1)+1) << ' ';
        for(j = i; j <= 4; j++)
        {
            cout << j << " ";
        }
        for(j = 4; j >= i; j--) 
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
