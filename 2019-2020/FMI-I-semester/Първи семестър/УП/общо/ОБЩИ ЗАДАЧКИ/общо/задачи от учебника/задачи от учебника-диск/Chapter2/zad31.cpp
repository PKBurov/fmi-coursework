#include <iostream.h>

int main()
{ 
    int x = 0,
        firstDigit = 0,
        secondDigit = 0;
    cout << "Въведете положително двуцифрено число: ";
    cin >> x;

    firstDigit = x/10;		  // цифра на десетиците
    secondDigit = x%10;		  // цифра на единиците

    if(firstDigit == 1)
    { 
        switch(secondDigit)
        { 
        case 1: cout << "Едина"; break;
        case 2: cout << "Двана"; break;
        case 3: cout << "Трина"; break;
        case 4: cout << "Четирина"; break;
        case 5: cout << "Петна"; break;
        case 6: cout << "Шестна"; break;
        case 7: cout << "Седемна"; break;
        case 8: cout << "Осемна"; break;
        case 9: cout << "Деветна";
        }
        cout << "десет.";
    }
    else
    { 
        switch(firstDigit)
        { 
        case 2: cout << "Двадесет"; break;
        case 3: cout << "Тридесет"; break;
        case 4: cout << "Четиридесет"; break;
        case 5: cout << "Петдесет"; break;
        case 6: cout << "Шестдесет"; break;
        case 7: cout << "Седемдесет"; break;
        case 8: cout << "Осемдесет"; break;
        case 9: cout << "Деветдесет";
        }
        if(secondDigit != 0)
        {
            cout << " и ";
        }
        switch(secondDigit)
        {
        case 1: cout << "едно"; break;
        case 2: cout << "две"; break;
        case 3: cout << "три"; break;
        case 4: cout << "четири"; break;
        case 5: cout << "пет"; break;
        case 6: cout << "шест"; break;
        case 7: cout << "седем"; break;
        case 8: cout << "осем"; break;
        case 9: cout << "девет";
        }
        cout << ".";
    }

    cout << endl;
    return 0;
}
