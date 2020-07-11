#include <iostream.h>
#include <string.h>
const int MAX_SIZE = 20;

int main()
{
    char s1[MAX_SIZE], s2[MAX_SIZE];
    // масивът function показва всяка от намерените
    // до момента стойности на функцията. Използва
    // се 0 за обозначаване на неопределена стойност
    char function[26] = {0,};
    cout << "s1= ";
    cin >> s1;
    cout << "s2= ";
    cin >> s2;

    // дължина и брояч
    unsigned int l = strlen(s1);
    unsigned int i = 0;

    if(l > strlen(s2))
    {
        cout << "Свойството не е в сила.\n";
    }
    else
    {   // изпълнението завършва, когато низовете се изчерпат
        // или е намерена двузначност на изображението
        while(i < l && (function[s1[i]-'a'] == 0 ||
                        function[s1[i]-'a'] == s2[i]))
        {
            function[s1[i]-'a'] = s2[i];
            i++;
        }
        if(i == l)
        {
            cout << "Свойството е в сила.\n";
        }
        else
        {
            cout << "Свойството не е в сила.\n";
        }
    }
    return 0;
}
