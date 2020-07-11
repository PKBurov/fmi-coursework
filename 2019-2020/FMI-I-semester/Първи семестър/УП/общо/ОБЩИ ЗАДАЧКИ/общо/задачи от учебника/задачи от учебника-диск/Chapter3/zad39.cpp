#include <iostream.h>
#include <math.h>
const int MAX_SIZE = 20;

int main()
{
    cout << "Въведете стойност на n в интервала "
            "[2, " << MAX_SIZE << "]: ";
    int n;
    cin >> n;
    double x[2][MAX_SIZE];

    // Въвеждане на матрицата x
    int i, j;
    cout << "Въведете 2 реда с по " << n << " реални числа.\n";
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> x[i][j];
        }
    }

    double maxd = 0,  // максимално разстояние две между точки
           d;         // текщо разстояние между две точки
    int maxi = 0,     // пореден номер на първата точка
        maxj = 1;     // пореден номер на втората точка
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        { 
            d = sqrt((x[0][j]-x[0][i])*(x[0][j]-x[0][i])+
                     (x[1][j]-x[1][i])*(x[1][j]-x[1][i]));
            if(d > maxd)
            { 
                maxd = d;
                maxi = i;
                maxj = j;
            }
        }
    }

    cout << "Максималното разстояние е: " << maxd << endl;
    cout << "Поредните номера на точките, между които "
         << "се получава максималното разстояние са:("
         << maxi << ", " << maxj << ")\n";
    return 0;
}
