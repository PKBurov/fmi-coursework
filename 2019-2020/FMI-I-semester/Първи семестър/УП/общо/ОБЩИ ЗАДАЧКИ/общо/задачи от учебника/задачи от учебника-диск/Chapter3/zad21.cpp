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
    cout << "Въведете редицата a!\n";
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    int b[MAX_SIZE];
    // Въвеждане на елементите на редицата b
    cout << "Въведете редицата b!\n";
    for(i = 0; i < n; i++)
    {
        cout << "b[" << i << "]= ";
        cin >> b[i];
    }

    // проверка дали всеки елемент на редицата b
    // принадлежи на редицата a
    bool flag = true;
    int j;
    i = 0; 
    while(i < n && flag)
    { 
        j = -1;
        do
        {
            j++;
        }while(a[j] != b[i] && j < n-1);

        if(a[j] != b[i])
        {
            flag = false;
        }
        i++;
    }

    if(!flag) 
    {
        cout << "Редиците не си приличат\n"; 
    }
    else
    {   // проверка дали всеки елемент на редицата a
        // принадлежи на редицата b
        j = 0;
        while(j < n && flag)
        { 
            int i = -1;
            do
            {
                i++;
            }while(b[i] != a[j] && i < n-1);

            if(b[i] != a[j])
            {
                flag = false;
            }
            j++;
        }

        if(flag)
        {
            cout << "Редиците си приличат \n";
        }
        else
        {
            cout << "Редиците не си приличат \n";
        }
    }
    return 0;
}
