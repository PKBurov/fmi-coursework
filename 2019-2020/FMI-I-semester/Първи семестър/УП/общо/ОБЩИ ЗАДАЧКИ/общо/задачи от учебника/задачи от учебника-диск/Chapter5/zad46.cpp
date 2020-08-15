#include <iostream.h>

const int MAX_N = 100;
const int MAX_K = 100;

int signs[MAX_N];
int elems[MAX_K];
int values[MAX_N];
int n, k;

void printExpr()
{ 
    cout << values[0];
    for(int i = 0; i < n; i++)
    {
        cout << (char)signs[i] << values[i+1];
    }
    cout << "\n";
}

// намира стойността на израза
int calc()
{ 
    int res = values[0];        // започва се от първото число
    for(int i = 0; i < n; i++)  // и за всеки знак се изпълнява
    { 
        switch(signs[i])        // съответната операция
        { 
        case '+': res += values[i+1]; break;
        case '-': res -= values[i+1]; break;
        case '*': res *= values[i+1]; break;
        case '/': res /= values[i+1]; break;
        }
    }
    return res;
}

bool solve(int i)
{
    if(i > n) 
        return false;

    // Ако е генерирана вариация с повторения и
    // за нея се получава исканата стойност
    if(i == n)
    {
        if(calc() == k)
        { 
            printExpr();
            return true;
        }
    }
    else 
    {
        return false;
    }
    for(int j = 0; j < 4; j++)      // за всички знаци
    { 
        signs[i] = elems[j];        // задава се текущият знак
        if(solve(i+1))              // генериране на
        {
            return true;            // останалите вариации с повторения
        }
    }
    return false;                   // не е намерено решение
}

int main()
{ 
    cin >> k >> n;
    elems[0] = '+'; elems[1] = '-'; 
    elems[2] = '*'; elems[3] = '/';

    for(int i = 0; i <= n; i++)
        cin >> values[i];

    if(!solve(0)) 
        cout << "Не е намерено решение.\n";
    return 0;
}
