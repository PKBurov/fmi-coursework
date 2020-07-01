#include <iostream.h>

int main()
{
    int n;
    do
    {
        cout << "Въведете стойност за n (n >= 1): ";
        cin >> n;
    } while(n < 1);

    int br = 0;
    for(int i = 1; i <= n; i = i+1)
    {
        int k = i*i*i + 13*i*n + n*n*n; 
        if (k % 5 == 0 || k % 9 == 0) br = br + 1;
    }
    cout << "Броят на елементите, кратни на 5 или 9 е "
         << br << endl;
    return 0;
}
