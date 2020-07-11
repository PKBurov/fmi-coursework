#include <iostream.h>
#include <string.h>
const int MAX_SIZE = 21;

int main()
{
    char s1[MAX_SIZE], s2[MAX_SIZE];
    cout << "s1= ";
    cin >> s1;
    cout << "s2= ";
    cin >> s2;
    // дължини и текущи позиции в l1 и l2
    int l1 = strlen(s1),
        l2 = strlen(s2),
        i1 = 0,
        i2 = 0;

    while(i1 < l1 && i2 < l2)
    {
        if(s1[i1] <= s2[i2])
        {
            cout << s1[i1];
            i1++;
        }
        else
        {
            cout << s2[i2];
            i2++;
        }
    }

    // в s1 или s2 може да са останали неизведени символи
    while(i1 < l1)
    { 
        cout << s1[i1];
        i1++;
    }
    while(i2 < l2)
    { 
        cout << s2[i2];
        i2++;
    }
    cout << endl;
    return 0;
}
