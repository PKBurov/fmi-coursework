#include <iostream.h>

int main()
{ 
    int month;
    cout << "month= ";
    cin >> month;
    cout << "Сезонът е ";

    switch(month)
    { 
    case 12:
    case 1:
    case 2: cout << "зима"; break;
    case 3:
    case 4:
    case 5: cout << "пролет"; break;
    case 6:
    case 7:
    case 8: cout << "лято"; break;
    case 9:
    case 10:
    case 11: cout << "есен"; break;
    default: cout << "неопределим. Въведен е "
                     "невалиден месец.\n";
    }
    cout << endl;
    return 0;
}
