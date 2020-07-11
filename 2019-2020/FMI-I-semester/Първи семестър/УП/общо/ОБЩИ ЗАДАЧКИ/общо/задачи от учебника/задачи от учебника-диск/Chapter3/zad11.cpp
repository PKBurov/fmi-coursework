#include <iostream.h>
const int MAX_SIZE = 100;

int main()
{
    cout << "Въведете стойност на n – цяло число от 1 до "
         <<  MAX_SIZE << ": ";
    int n;
    cin >> n;
    char s[MAX_SIZE];

    // Въвеждане на елементите на редицата s
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "s[" << i << "]= ";
        cin >> s[i];
    }

    // Извеждане на цифрите
    for(i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            cout << s[i] << " ";
        }
    }
    cout << endl;

    // Извеждане на малките латински букви
    for(i = 0; i < n; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            cout << s[i] << " ";
        }
    }
    cout << endl;	

    // Извеждане на останалите символи
    for(i = 0; i < n; i++)
    {
        if((s[i] < '0' || s[i] > '9') && (s[i] < 'a' || s[i] > 'z')) 
        {
            cout << s[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
