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
    for (i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    // Въвеждане на елементите на редицата b
    int b[MAX_SIZE];
    for(i = 0; i < n; i++)
    {
        cout << "b[" << i << "]= ";
        cin >> b[i];
    }

    // намиране на броя на съответно равните елементи
    int br = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i] == b[i]) 
        {
            br++;
        }
    }
    if(br == n) 
    {
        cout << "Редиците са равни.\n";
    }
    else
    {
        cout << "Редиците не са равни. \n";
    }
    return 0;
}
