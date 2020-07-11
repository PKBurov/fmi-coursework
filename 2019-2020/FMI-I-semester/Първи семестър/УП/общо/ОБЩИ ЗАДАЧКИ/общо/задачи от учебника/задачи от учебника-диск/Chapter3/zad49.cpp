#include <iostream.h>
const int MAX_SIZE = 10;

int main()	
{
    int a[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE*MAX_SIZE/2];
    int n;
    cout << "Въведете размерност на матрицата [1, "
         << MAX_SIZE << "]\n";
    do
    {
        cout << "n= ";
        cin >> n;
    } while(n < 1 || n > MAX_SIZE);

    // въвеждане на стойности на елементите на матрицата
    int i;
    for(i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        { 
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }

    int count = 0;
    // обхождане елементите на матрицата под главния
    // диагонал, по линии успоредни на този диагонал
    for(i = 1; i < n; i++)
    {
        for(int j = 0; j < n - i; j++)
        { 
            result[count] = a[i + j][j];
            count++;
        }
    }

    // извеждане на резултата
    for(i = 0; i < count; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
