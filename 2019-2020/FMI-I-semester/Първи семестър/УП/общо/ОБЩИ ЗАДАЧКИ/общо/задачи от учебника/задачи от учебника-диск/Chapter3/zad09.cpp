#include <iostream.h>
const int MAX_SIZE = 20;

int main()
{
    cout << "Въведете стойност на n – цяло число от 1 до "
         <<  MAX_SIZE << ": ";
    int n; 
    cin >> n;
    int a[MAX_SIZE];

    // Въвеждане на редицата
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    int t       = 0,        // ще съдържа периода
        matched = 0; 		// помощна променлива
    // цикъл за проверка дали t+1 е период
    while(t <= n/2 && matched < n)
    {
        t++;
        matched = t;
        while(matched < n && a[matched-t] == a[matched])
        {
            matched++;
        }
    }
    if(t <= n/2)
    {
        cout << "Периодът е: " << t << endl;
    }
    else
    {
        cout << "В масива не съществува период.\n";
    }
    return 0;
}
