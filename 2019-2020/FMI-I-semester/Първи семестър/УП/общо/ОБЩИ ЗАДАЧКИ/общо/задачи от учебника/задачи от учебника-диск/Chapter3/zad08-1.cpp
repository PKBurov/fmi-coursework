#include <iostream.h>
const int MAX_SIZE = 100;

int main()
{
    cout << "Въведете стойност на n – цяло число от 1 до "
         <<  MAX_SIZE << ": ";
    int n;
    cin >> n;
    double a[MAX_SIZE];

    // Въвеждане на редицата
    int i;
    for (i = 0; i < n; i++)
    { 
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    int br = 0;
    for(i = 0; i <= n-2; i++)
    {
        if(a[i] <= a[i+1]) 
        {
            br++;
        }
    }
    if(br == n-1)
    {
        cout << "Редицата е монотонно растяща.\n";
    }
    else
    {
        cout << "Редицата не е монотонно растяща.\n";
    }
    return 0;
}
