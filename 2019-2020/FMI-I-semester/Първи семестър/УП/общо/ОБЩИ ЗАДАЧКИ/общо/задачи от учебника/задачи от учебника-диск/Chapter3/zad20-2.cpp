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

    // Въвеждане на елементите на редицата b
    int b[MAX_SIZE];
    for(i = 0; i < n; i++)
    {
        cout << "b[" << i << "]= ";
        cin >> b[i];
    }

    // проверка дали редиците са равни
    i = -1;
    do
    {
        i++;
    }while(a[i] == b[i] && i < n-1);

    if(a[i] != b[i])
    {
        cout << "Редиците не са равни.\n";
    }
    else
    {
        cout << "Редиците са равни.\n";
    }
    return 0;
}
