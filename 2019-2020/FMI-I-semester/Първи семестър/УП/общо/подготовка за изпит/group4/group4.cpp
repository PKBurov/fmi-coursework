#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>

/*
Група 4: За случайно инициализиран масив от 16 малки латински букви да се генерира двоично число,
за което 0 = { a, b, c, d, e, f } , 1 = съгласна (всички останали).
Дa се изведе масива. Да се изведе числото в двоична и десетична форма.
*/

using namespace std;

const int ARRAY_LENGTH = 16;

int main()
{
    srand(time(NULL));
    char a [ARRAY_LENGTH];
    int range = 'z' - 'a' + 1;
    for (int i = 0; i < ARRAY_LENGTH; i++) {
            a[i] = rand() % range + 'a';
    }
    for (int i = 0; i < ARRAY_LENGTH; i++) {
            cout << a[i] << ' ';
    }
    cout << endl;

    long long result = 0;
    long long decimal = 0;
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        short binaryDigit = (a[i] < 'g' ? 0 : 1);
        result += binaryDigit * pow(10, ARRAY_LENGTH - 1 - i);
        decimal += binaryDigit * pow(2, ARRAY_LENGTH - 1 - i);
    }
    cout << "binary: " << result << endl;
    cout << "decimal: " << decimal << endl;
}
