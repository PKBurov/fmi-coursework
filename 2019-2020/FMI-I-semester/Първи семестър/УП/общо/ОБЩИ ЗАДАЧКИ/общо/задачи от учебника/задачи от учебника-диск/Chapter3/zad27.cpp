#include <iostream.h>
const int MAX_SIZE = 20;

int main()
{
    cout << "Въведете броя на цифрите на първото число n – "
            "цяло число от 1 до " << MAX_SIZE << ": ";
    int n;
    cin >> n;
    char s1[MAX_SIZE];

    // Въвеждане на първото неотрицателно цяло число
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "s1[" << i << "]= ";
        cin >> s1[i];
    }

    cout << "Въведете броя на цифрите на второто число m – "
            "цяло число от 1 до " << MAX_SIZE << ": ";
    int m; 
    cin >> m;    
    char s2[MAX_SIZE];

    // Въвеждане на второто неотрицателно цяло число
    for(i = 0; i < m; i++)
    {
        cout << "s2[" << i << "]= ";
        cin >> s2[i];
    }

    bool flag;
    if(n > m)
    {
        flag = true;
    }
    else
    {
        if(n < m) flag = false;
        else
        { 
            i = n-1;
            while(s1[i] == s2[i] && i > 0)
            {
                i--;
            }
            if(s1[i] != s2[i])
            {
                flag = s1[i] > s2[i];
            }
            else
            {
                flag = false;
            }
        }
    }

    if(flag)
    {
        cout << "Първото число е по-голямо от второто.\n";
    }
    else
    {
        cout << "Първото число не е по-голямо от второто.\n";
    }
    return 0;
}
