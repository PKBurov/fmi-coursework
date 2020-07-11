#include <iostream.h>
const int MAX_SIZE = 100;

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
    int subStart = 0,
        subEnd = 0,
        maxLen = 0;
    for(i = 0; i < n-1; i++)
    {
        if(a[i+1] >= a[i])
        {
            subEnd++;
        }
        else
        {
            if(maxLen < subEnd-subStart+1)
            {
                maxLen = subEnd-subStart+1;
            }
            subStart = i+1;
            subEnd = subStart;
        }
    }
    if(maxLen < subEnd-subStart+1)
    {
        maxLen = subEnd-subStart+1;
    }
    cout << maxLen << endl;
    return 0;
}

