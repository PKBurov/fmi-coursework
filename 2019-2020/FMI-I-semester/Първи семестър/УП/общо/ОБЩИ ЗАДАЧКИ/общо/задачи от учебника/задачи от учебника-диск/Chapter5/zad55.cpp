#include <iostream.h>

bool expression();

int main()
{
    cout << expression() << "\n";
    return 0;
}

bool expression()
{ 
    char c;
    bool x, y;

    cin >> c;                   // c е t или f или n, a или o
    if(c == 't') return true;
    if(c == 'f') return false;

    // <израз> ::= <операция>(<операнди>)
    switch(c)
    {
    case 'n':
        cin >> c;               // прескачане на '('
        x = expression();
        cin >> c;               // прескачане на ')'
        return !x;

    case 'a':
        cin >> c;               // прескачане на '('
        x = expression();
        cin >> c;               // ',' или ')'
        while(c == ',')
        { 
            y = expression();
            x = x && y;
            cin >> c;           // прескачане на ',' или ')'
        }
        return x;

    case 'o':
        cin >> c;               // прескачане на '('
        x = expression();
        cin >> c;               // ',' или ')'
        while(c == ',')
        {
            y = expression();
            x = x || y;
            cin >> c;           // прескачане на ',' или ')'
        }
        return x;

    default: 
        cout << "Error! \n"; 
        return false;
    }
}

