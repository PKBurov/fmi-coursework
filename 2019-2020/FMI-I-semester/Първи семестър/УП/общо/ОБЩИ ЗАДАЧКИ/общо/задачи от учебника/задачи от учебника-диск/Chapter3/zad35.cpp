#include <iostream.h>
#include <math.h>
const int MAX_SIZE = 20;

int main()
{
    int a[MAX_SIZE][MAX_SIZE];
    int n;
    cout << "Въведете размерност на матрицата <= " 
         << MAX_SIZE << "\n";
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
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    // намиране сумата на елементите под главния диагонал
    // (включително с него), които са прости числа
    int sum = 0;
    for(i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {   // проверка дали a[i][j] е просто число
            bool prime = true;
            if(a[i][j] == 1 || (a[i][j] != 2 && a[i][j]%2 == 0))
            {
                prime = false;
            }

            int k = 3;
            while(k <= a[i][j]/2 && prime)
            {
                if(a[i][j] % k == 0)
                {
                    prime = false;
                }
                k = k+2;
            }
            if(prime)
            {
                sum += a[i][j];
            }
        }
    }

    cout << "Сумата на простите числа под главния диагонал "
            " (включително с него) е " << sum << endl;

    // намиране произведението на елементите над главния
    // диагонал (включително с него), в записа на които
    // се съдържа цифрата 5
    int product = 1;
    for(i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {   // проверка  дали в записа на a[i][j]
            // се съдържа цифрата 5
            int temp = abs(a[i][j]);
            bool found = false;
            while(temp && !found)
            { 
                if(temp % 10 == 5)
                {
                    found = true;
                }
                temp = temp / 10;
            }
            if(found)
            {
                product = product * a[i][j];
            }
        }
    }

    cout << "Произведението на елементите над главния "
            "диагонал (включително с него), в чиито запис се "
            "съдържа цифрата 5 е " << product << endl;

    // намиране броя на симетричните числа под вторичния
    // главен диагонал (включително с него)
    int count = 0;
    for(i = 0; i < n; i++)
    {
        for(int j = n-i-1; j < n; j++)
        {   // проверка дали a[i][j] е симетрично число
            int temp = abs(a[i][j]);
            int reverse = 0;
            while(temp)
            { 
                reverse = reverse*10 + temp % 10;
                temp = temp / 10;
            }
            if(reverse == abs(a[i][j]))
            {
                count++;
            }
        }
    }
    cout << "Броят на симетричните числа под вторичния "
            "главен диагонал (включително с него), е "
         << count << endl;
    return 0;
}
