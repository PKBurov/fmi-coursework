#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

#include <cstring>

#include <stack>
using std::stack;

/*
    Да се преобразува израз от инфиксен в обратен полски запис...
    2 + 3 * 5 - 6
    2 3 5 * + 6 -

    операциите са бинарни, с еднаква асоциативност
    операндите са цифрите от 0-9
*/

// function е указател към функция, която получава два аргумента
// от тип double и връща като резултат double (заради деленето...)
typedef double (*function)(double, double);

// приемаме, че операциите са бинарни, с еднаква асоциативност
class Operation
{
    public:

        Operation(int prec = 0, char s = 0, function f = NULL)
            : precedence(prec), symbol(s), calc(f)
        {
            // празно тяло, всичко е качено в инициализиращи списък
        }

        // селектори и мутатори
        int getPrecedence() const
        {
            return precedence;
        }

        const function getFunction() const
        {
            return calc;
        }

        char getSymbol() const
        {
            return symbol;
        }

        bool isEmpty() const
        {
            // изключваме ( и фиктивния елемент за край
            return 0 == symbol || calc == NULL;
        }

        bool hasSameSymbol(char op)
        {
            return symbol == op;
        }

    private:
        int precedence;
        char symbol;
        // указател към функция, която извършва изчислението
        function calc;
};

double sum(double a, double b)
{
    return a + b;
}

double substract(double a, double b)
{
    return a - b;
}

double prod(double a, double b)
{
    return a * b;
}

double div(double a, double b)
{
    // проверката трябва да се направи с eps,
    // има ли изобщо нужда от проверка, когато типът е double?
    if(0 == b)
        throw "Divide by zero...";

    return a / b;
}

// начална инициализация на операциите
Operation operations[] = {
    Operation(5, '+', sum),
    Operation(5, '-', substract),
    Operation(10, '*', prod),
    Operation(10, '/', div),
    Operation(0, '(', NULL), // изкуствено е с най-нисък приоритет
    Operation() // фиктивен елемент за края на операциите
};

/*
    Shunting Yard Algorithm
    Алгоритъм за преобразуване на инфиксен израз в постфиксен.
    1. Прочитаме символ.
    2. Ако символът е число, добавяме го в изходния низ.
    3. Ако символът е (, добавяме го в стек с операции.
    4. Ако символът е ), изваждаме от стека всички операции до (.
    5. Ако символът е операция, от стека се вадят всички операции, които са с по-висок приоритет.
    6. Ако няма повече символи в израза, от стека се изваждат всички останали операции.
    7. Ако в стека има отваряща скоба, влагането на скобите е било неправилно.

    Алгоритъмът не проверява за пълна коректност на израза. Пример: 3 (+2)
*/

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

Operation& getOperation(char c)
{
    int i = 0;

    while(!operations[i].isEmpty())
    {
        if(operations[i].hasSameSymbol(c))
            break; // return operations[i];

        ++i;
    }

    // такава операция не съществува
    return operations[i]; // Operation();
}

// преобразува инфиксен израз в постфиксен
// expr е изходния израз, записан инфиксно
// rpn е резулзатния израз, в постфиксен вариант
bool convertToRPN(const char* expr, char* rpn)
{
    stack<Operation> opStack;

    while(*expr)
    {
        if(isDigit(*expr))
        {
            // Обработваме цифра, записваме я на изхода
            *rpn = *expr;
            ++rpn;
        }
        else
        {
            if(*expr == '(')
            {
                Operation op = getOperation(*expr);
                opStack.push(op);
            }
            else if (*expr == ')')
            {
                Operation op;
                while(!opStack.empty())
                {
                    op = opStack.top();
                    opStack.pop();

                    if(op.hasSameSymbol('('))
                        break;

                    *rpn = op.getSymbol();
                    ++rpn;
                }

                // по каква причина сме прекъснали?
                // възможно ли е в стека изобщо да няма (
                if(opStack.empty())
                {
                    cerr << "Unexpected token \')\'!\n";
                    return false;
                }
            }
            else
            {
                // ако символът е операция
                Operation op = getOperation(*expr);
                if(!op.isEmpty())
                {
                    // текущият символ е операция, да се извадят от стека
                    // всички операции, които са с по-висок или равен приоритет
                    Operation otherOp;

                    bool lowerPrecedenceFound = false;
                    while(!opStack.empty() && !lowerPrecedenceFound)
                    {
                        otherOp = opStack.top();
                        if(otherOp.getPrecedence() >= op.getPrecedence())
                        {
                            // >= има значението на лявоасоциативни операции
                            // ако е само >, тогава имаме дясна асоциативност
                            opStack.pop();
                            *rpn = otherOp.getSymbol();
                            ++rpn;
                        }
                        else
                        {
                            // операция с по-малък приоритет е на върха на стека
                            lowerPrecedenceFound = true;
                        }
                    }

                    // добавяме новата операция към стека с операциите...
                    opStack.push(op);
                }
                else
                {
                    // съвсем различен символ....
                    if(*expr != ' ')
                    {
                        cerr << "Unexpected token " << *expr << "!\n";
                        return false;
                    }
                }
            }
        }

        // преминаваме към следващия символ
        ++expr;
    }

    Operation op;
    // какво е останало в стека?
    while(!opStack.empty())
    {
        op = opStack.top();
        opStack.pop();

        if(op.hasSameSymbol('('))
        {
            cerr << "Unexpected token \'(\'!\n";
            return false;
        }

        *rpn = op.getSymbol();
        ++rpn;
    }

    // терминиращата нула на резултатния низ...
    *rpn = '\0';
    return true;
}

double calculate(const char* rpn)
{
    stack<double> res;

    while(*rpn)
    {
        if(isDigit(*rpn))
        {
            res.push(*rpn - '0');
        }
        else
        {
            // приемаме, че изразът е коректен и имаме или цифри или операции
            Operation op = getOperation(*rpn);
            if (!op.isEmpty())
            {
                bool errorDetected = true;

                // операциите са бинарни
                double left, right;
                if(!res.empty())
                {
                    right = res.top();
                    res.pop();

                    if(!res.empty())
                    {
                        left = res.top();
                        res.pop();

                        function f = op.getFunction();
                        // пъхаме в стека резултата от операцията
                        // Има значение какъв е реда на операндите при - и /
                        res.push(f(left, right));

                        errorDetected = false;
                    }
                }

                if(errorDetected)
                {
                    throw "The postfix expression is not valid!";
                }
            }
        }

        ++rpn;
    }

    // в стека трябва да има един единствен елемент
    if(res.empty())
    {
        throw "The postfix expression is not valid!";
    }

    double result = res.top();
    res.pop();

    if(!res.empty())
        throw "The postfix expression is not valid!";

    return result;
}

void testRPN(const char* expr)
{
    cout << "Infix expression: " << expr << endl;

    char* rpn = new char[strlen(expr) + 1];
    try
    {
        if(convertToRPN(expr, rpn))
        {
            cout << "Postfix expression: " << rpn << endl;
            cout << "The value of the expression is: " << calculate(rpn) << endl;
        }
        else
        {
            cout << "The infix expression was not converted to postfix one!\n";
        }
    }
    catch(const char* e)
    {
        cout << e << endl;
    }

    // освобождаваме динамичната памет
    delete [] rpn;
}

void testRPN()
{
    const char* expr = "1 + 2 + 2 * 3 * 4 + 6 * 2 + 1 / 2";
    testRPN(expr);

    cout << endl;

    expr = "1 + (2 + 2) * 3 * 4 + 6 * 2 + 1 / 2";
    testRPN(expr);

    cout << endl;
    expr = "(1 + (2 + 2) * 3 * (4 + 6) * 2 + 1) / 2";
    testRPN(expr);

    cout << endl;
    expr = "3 + 4 - (3 * 5) / 2";
    testRPN(expr);

    cout << endl;
    expr = "3 + 4 - 3 * 5) / 2";
    testRPN(expr);
}

int main()
{
    testRPN();

    return 0;
}
