#include <iostream.h>
const int MAX_SIZE = 100;

int main()
{
    cout << "Въведете стойност на n – цяло число от 1 до "
         <<  MAX_SIZE << ": ";
    int n; 
    cin >> n;
    int a[MAX_SIZE];

    // Въвеждане на елементите на редицата
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    // намиране на минималния елемент на редицата
    int min = a[0];
    for(i = 1; i < n; i++)
    {
        if(a[i] < min)
        {
            min = a[i];
        }
    }
  
    // извеждане на минималния елемент
    cout << "min{a[0], ..., a[" << n-1 << "]} = "
         << min << endl;
    return 0;
}
