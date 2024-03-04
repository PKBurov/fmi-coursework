#include <iostream>

using std::cout;
using std::endl;

#include <cstring>

#include <stack>
using std::stack;

/*
    Да се провери дали употребата на скоби в даден израз (низ) е коректна.
    Разпознават се следните видове скоби {}, (), [], <>.
*/

const char* openBraces = "{([<";
// съответните затварящи скоби
const char* closeBraces = "})]>";

// проверява дали е отваяща скоба
bool isOpen(char c)
{
    // търси първото срещане на посочения символ в низа и връща указател към него
    // ако символът не е открит, връща NULL
    return strchr(openBraces, c) != NULL;
}

// проверява дали е затваряща скоба
bool isClose(char c)
{
    return strchr(closeBraces, c) != NULL;
}

bool isMatch(char open, char close)
{
    int openIndex = strchr(openBraces, open) - openBraces;
    int closeIndex = strchr(closeBraces, close) - closeBraces;

    return openIndex == closeIndex;
}

bool balancedBraces(const char* text)
{
    // стек от символи, в който ще се записват скобите
    stack<char> cs;

    while(*text)
    {
        if(isOpen(*text))
        {
            // прочели сме отваряща скоба
            cs.push(*text);
        }
        else
        {
            if(isClose(*text))
            {
                // затваряща скоба, дали на върха на стека има съответната отваряща?
                if(cs.empty())
                    return false;

                char open = cs.top();
                if(!isMatch(open, *text))
                    return false;
            }
        }

        // преминаваме към следващия символ
        text ++;
    }

    return cs.empty();
}

void testBalancedBraces(const char* text)
{
    cout << text << endl << "Braces are ";

    if(!balancedBraces(text))
    {
        cout << "NOT ";
    }

    cout << "balanced!\n";
}

void testBalancedBraces()
{
    const char* text = "Correct ( use of { open and close } braces )...";
    testBalancedBraces(text);

    text = "Wrong ( it is (. Is it not? )}";
    testBalancedBraces(text);

    text = "One ) more time wrong (";
    testBalancedBraces(text);
}

int main()
{
    testBalancedBraces();

    return 0;
}
