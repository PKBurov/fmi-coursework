#include <iostream.h>

int main()
{
    for(int a = 1; a <= 9; a++)         // a е между 1 и 9
    {
        for(int c = 0; c <= 9-a; c++)   // c може да е от 0 до 9-а
        {
            int b = a + c;              // Получава се b с  исканото свойство
            cout << a << b << c << " ";
        }
    }
    return 0; 
}
