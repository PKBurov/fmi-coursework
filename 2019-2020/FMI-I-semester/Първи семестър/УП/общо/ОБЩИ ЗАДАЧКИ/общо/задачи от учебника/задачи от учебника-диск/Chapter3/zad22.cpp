#include <iostream.h>
const int MAX_SIZE = 50;

int main()
{
    cout << "Въведете стойност на n – цяло число от 1 до "
         <<  MAX_SIZE << ": ";
    int n;
    cin >> n;
    int a[MAX_SIZE];

    // Въвеждане на елементите на редицата a
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    cout << "Въведете стойност на m – цяло число от 1 до "
         <<  MAX_SIZE << ": ";
    int m;
    cin >> m;
    int b[MAX_SIZE];

    // Въвеждане на елементите на редицата b
    for(i = 0; i < m; i++)
    {
        cout << "b[" << i << "]= ";
        cin >> b[i];
    }
    int br = 0;

    if(n <= m)
    { 
        for(i = 0; i <= m-n; i++)
        { 
            int j = -1;
            do
            {
                j++;
            }while(a[j] == b[j+i] && j < n-1);

            if(a[j] == b[j+i]) 
            {
                br++;
            }
        }
    }
    cout << "Първата редица се съдържа във втората " 
         << br << " пъти.\n";
    return 0;
}
