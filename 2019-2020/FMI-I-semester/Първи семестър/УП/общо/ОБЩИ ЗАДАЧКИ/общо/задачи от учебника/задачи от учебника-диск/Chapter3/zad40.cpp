#include <iostream.h>
const int MAX_SIZE = 20;

int main()
{
    cout << "Въведете стойност на n в интервала "
        "[1, " << MAX_SIZE << "]: ";
    int n; 
    cin >> n;
    int x[2][MAX_SIZE];

    // Въвеждане на матрицата x
    int i, j;
    cout << "Въведете 2 реда с по " << n << " цели числа.\n";
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> x[i][j];
        }
    }

    bool flag = true;
    for(i = 0; i < n-1 && flag; i++)
    {
        for(j = i+1; j < n && flag; j++)
        {
            if(x[0][i]==x[0][j] && x[1][i]!=x[1][j])
            {
                flag = false;
            }
        }
    }

    if(flag)
    {
        cout << "Множеството M дефинира функция.\n";
    }
    else
    {
        cout << "Множеството M не дефинира функция.\n";
    }
    return 0;
}
