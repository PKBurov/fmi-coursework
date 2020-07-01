#include <iostream.h>

int main()
{ 
    int month;
    cout << "month= ";
    cin >> month;

    switch(month)
    { 
    case 1: cout << "Януари"; break;
    case 2: cout << "Февруари"; break;
    case 3: cout << "Март"; break;
    case 4: cout << "Април"; break;
    case 5: cout << "Май"; break;
    case 6: cout << "Юни"; break;
    case 7: cout << "Юли"; break;
    case 8: cout << "Август"; break;
    case 9: cout << "Септември"; break;
    case 10: cout << "Октомври"; break;
    case 11: cout << "Ноември"; break;
    case 12: cout << "Декември"; break;
    default: cout << "Въведена е неправилна"
                      "стойност за месеца!";
    }

    cout << endl;
    return 0;
}
