#include <iostream.h>
#include <string.h>
const int MAX_SIZE = 100;

int main()
{
    char s[MAX_SIZE];
    unsigned int histogram[26] = {0,};
    unsigned int i = 0;

    cout << "s= ";
    cin >> s;
    for(i = 0; i < strlen(s); i++)
    {
        histogram[s[i]-'a']++;
    }
    for(i = 0; i < 26; i++)
    {
        if(histogram[i] > 0)
        {
            cout << (char)('a'+i) << ": " 
                 << histogram[i] << endl;
        }
    }
    return 0;
}
