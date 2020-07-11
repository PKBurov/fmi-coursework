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

    // Въвеждане на x
    cout << "Въведете цяло число - стойност на x: ";
    int x; 
    cin >> x;

    // проверка дали съществува a[i], което да е равно на x
    i = -1;
    do
    {
        i++;
    }while(a[i] != x && i < n-1);

    if(a[i] == x)
    {
        cout << "В редицата има елемент равен на дадения.\n";
    }
    else
    {
        cout << "В редицата няма елемент равен на дадения.\n";
    }
    return 0;
}
