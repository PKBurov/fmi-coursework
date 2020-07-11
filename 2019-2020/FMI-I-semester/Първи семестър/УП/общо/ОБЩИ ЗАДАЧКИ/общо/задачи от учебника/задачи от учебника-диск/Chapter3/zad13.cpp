#include <iostream.h>
const int MAX_SIZE = 100;

int main()
{
    cout << "Въведете стойност на n – цяло число от 1 до "
         <<  MAX_SIZE << ": ";
    int n; 
    cin >> n;
    char s[MAX_SIZE];
    
    // Въвеждане на елементите на редицата от цифри s
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "s[" << i << "]= ";
        cin >> s[i];
    }

    // проверка дали редицата е симетрична
    i = 0;
    while(s[i] == s[n-i-1] && i < n/2)
    {
        i++;
    }

    if(s[i] == s[n-i-1])
    {
        cout << "Редицата е симетрична.\n";
    }
    else
    {
        cout << "Редицата не е симетрична.\n";
    }
    return 0;
}
