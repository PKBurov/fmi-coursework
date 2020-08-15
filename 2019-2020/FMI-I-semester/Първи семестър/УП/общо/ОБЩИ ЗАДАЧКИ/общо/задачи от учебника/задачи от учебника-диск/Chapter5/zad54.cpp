#include <iostream.h>

int expression();

int main()
{ 
    cout << expression() << "\n";
    return 0;
}

int expression()
{ 
    char c, op;
    int x, y;
    c = cin.peek();               // c е '(', '+', '-' или цифра
    if(c == '+' || c == '-' || c >= '0' && c <= '9')
    { 
        // <израз> ::= <цяло_число>
        int n; 
        cin >> n;
        return n;
    }
    else  // <израз> ::= (<израз><знак><израз>)
    { 
        cin >> c;															// прескачане на '('
        x = expression();       // намиране стойността на първия израз
        cin >> op;		            // намиране на операцията
        y = expression();       // намиране стойността на втория израз
        cin >> c;               // прескачане на ')'
        // намиране на стойността на израза
        switch (op)
        { 
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        default: cout << "Error! \n"; return 111;
        }
    }
}
