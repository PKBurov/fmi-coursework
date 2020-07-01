#include <iostream.h>

int main()
{ 
    double a, b;
    cout << "a= ";
    cin >> a;
    cout << "b= ";
    cin >> b;

    if(a == 0)
    { 
        if(b == 0)
        {
            cout << "Всяко х е решение.\n ";
        }
        else
        {
            cout << "Уравнението няма решение.\n ";
        }
    }
    else
    {
        cout << "Решението на уравнението е х = " 
             << b/a << endl;
    }
    return 0;
}
