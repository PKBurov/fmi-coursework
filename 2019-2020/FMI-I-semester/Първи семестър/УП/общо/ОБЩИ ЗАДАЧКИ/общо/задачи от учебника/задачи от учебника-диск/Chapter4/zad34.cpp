#include <iostream.h>
#include <string.h>

const int MAX_LEN = 100;
int IsRealNumber(char* text, char* tokens)
{ 
    char sym;
    int condition = 0;
    int digitCountBeforePoint = 0;
    int digitCountAfterPoint = 0;
    int digitCountAfterE = 0;

    while(sym = *text)
    {
        // Знак
        if(sym == '-' || sym == '+')
        {
            if(condition == 0) condition = 1;              // начало
            else if(condition == 5) condition = 6;         // след Е
            else return 0;                                 // грешка
        }
        // Цифра
        else if(sym >= '0' && sym <= '9')
        { 
            if(condition <= 2)     			                // преди цифри
            { 
                digitCountBeforePoint++;
                condition = 2;   		                    // започва числото
            }
            else if(condition == 3)
            {
                digitCountAfterPoint++;                     // след точка
            }
            else if(condition >= 5 && condition <= 7)
            { 
                digitCountAfterE++;                         //експонента
                condition = 7;
            }
            else return 0;                                  //Не се очакват цифри
        }
        // Точка
        else if(sym == '.')
        { 
            if(condition == 2)                              //Ако сме в цялата част
            {
                condition = 3;
            }
            else return 0;
        }
        // Експонента
        else if(sym == 'E' || sym == 'e')
        {   // Трябва да има поне една цифра от числото
            if(condition >= 2 && condition <= 4 &&
                digitCountBeforePoint + digitCountAfterPoint > 0)
            {
                condition = 5;
            }
            else return 0;
        }
        // Друг символ, който не е от числото
        else
        { 
            if(!strchr(tokens, sym))
                return 0;                                   // Невалиден символ
            if(condition >= 2 && condition < 4)
            {
                condition = 4;                              // Очаква се експонента
            }
            // След цифрите или след експонента
            // се обявява краят на числото
            else if(condition == 4 || condition >= 7)
            {
                condition = 8;
            }
            else if(condition >= 2)
                return 0;                                   // Числото е невалидно
        }
        text++;
    }
    if((condition == 2 || condition == 3 ||
        condition == 4 || condition >= 7) &&
        (digitCountBeforePoint + digitCountAfterPoint > 0))
        return 1;
    return 0;
}

int main()
{
    char text1[MAX_LEN], text2[MAX_LEN] = "abcdfgh,;pqrs";
    cin.getline(text1, MAX_LEN);
    cout << IsRealNumber(text1, text2) << endl;
    return 0;
}
