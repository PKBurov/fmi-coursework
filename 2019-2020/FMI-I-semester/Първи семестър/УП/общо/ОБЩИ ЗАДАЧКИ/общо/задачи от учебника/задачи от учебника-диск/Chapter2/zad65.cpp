#include <iostream.h>

int main()
{
    int n; 
    do
    {
        cout << "Въведете положително цяло число: ";
        cin >> n;
    } while(n <= 0);

    // намиране на броя на цифрите на n
    int len = 0, a = n;
    while(a != 0)
    {
        len++;
        a = a/10;
    }

    int k;
    do
    {
        cout << "Въведете цяло число от 1 до "
             << len << " : ";
        cin >> k;
    } while(k < 1 || k > len);

    int p = 1;
    for(int j = 1; j <= len-k; j++)
    {
        p = p*10;
    }

    int m = n/(p*10)*p + n%p;
    cout << "След задраскване на " << k
         << "-тата отляво надясно цифра на числото "
         << n << " се получава числото " << m << endl;
    return 0;
}
