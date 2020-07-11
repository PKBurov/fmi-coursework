#include <iostream.h>
const int MAX_SIZE = 20;

int main()
{
    cout << "Въведете стойност на n в интервала "
            "[1, " << MAX_SIZE << "]: ";
    int n; 
    cin >> n;
    double x[2][MAX_SIZE];

    // въвеждане на матрицата x
    int i, j;
    cout << "Въведете 2 реда с по " << n << " реални числа.\n";
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> x[i][j];
        }
    }

    int number = 0;
    for(i = 0; i < n; i++)
    {
        if (x[0][i] <= 10 && x[1][i] <= 10 &&
            x[1][i] - x[0][i] <= 3 && x[0][i] + x[1][i] >= 6)
        {
            number++;
            cout << "(" << x[0][i] << ", " << x[1][i] << ")\n";
        }
    }
    cout << "Броят на точките принадлежащи на областта А е "
         << number << endl;
    return 0;
}
