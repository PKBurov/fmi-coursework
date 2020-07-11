#include <iostream.h>
const int MAX_SIZE = 50;

int main()
{
    cout << "Въведете стойност на n – цяло число от 1 до "
         <<  MAX_SIZE << ": ";
    int n; 
    cin >> n;
    int a[MAX_SIZE];

    cout << "Въведете сортирана във възходящ ред "
            "редица от цели числа!\n";
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    int b[MAX_SIZE];
    cout << "Въведете сортирана във възходящ ред "
            "редица от цели числа!\n";
    for(i = 0; i < n; i++)
    {
        cout << "b[" << i << "]= ";
        cin >> b[i];
    }

    // намиране на броя на съответно равните елементи
    int br = 0;
    if(b[0] <= a[n-1])
    {
        for(i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(a[i] < b[j])
                {
                    break;
                }else if(a[i] == b[j])
                { 
                    br++;
                    if(j < n-1 && b[j] < b[j+1]) 
                    {
                        break;
                    }
                }
            }
        }
    }

    cout << "Броят на съответно равните елементи е: "
         << br << endl;
    return 0;
}
