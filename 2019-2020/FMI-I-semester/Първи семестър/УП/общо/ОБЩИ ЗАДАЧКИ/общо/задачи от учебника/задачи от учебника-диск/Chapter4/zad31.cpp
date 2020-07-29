#include <iostream.h>
#include <string.h>

const int MAX_LEN = 100;

// Връща указател към първото срещане на разделител
// след символ неразделител. Ако няма такова срещане - 
// връща NULL
const char* nextToken(const char* text,
                      const char* delimeters)
{
    while(*text && strchr(delimeters, *text))
        ++text;
    if(!*text)
    {
        return NULL;
    }
    while(!(strchr(delimeters, *text)))
        ++text;
    return text;
}

// Преброява частите, на които ще бъде разделен низът
int tokenCnt(const char* text, const char* delimeters)
{
    int cnt = 0;
    const char* p = text;
    while(p = nextToken(p, delimeters))
        ++cnt;
    return cnt;
}

// Извършва разделянето.
// Връща масив от частите, на които е разделен низът.
// Заделя памет за самите части и за масива от тях
char** tokenize(const char* text, const char* delimeters,
                char**& tokens, int& num)
{
    num = tokenCnt(text, delimeters);
    tokens = new char*[num];
    const char* start = text;
    const char* end;
    for(int i = 0; i < num; ++i)
    {
        end = nextToken(start, delimeters);
        if(end)
        {
            while(*text && strchr(delimeters, *text))
                ++text;
            int len = (int)(end - start);
            tokens[i] = new char[len + 1];
            strncpy(tokens[i], start, len);
            tokens[i][len] = '\0';
            start = end;
        }
    }
    return tokens;
}

int main()
{
    char text[MAX_LEN];
    char* delims = ",; -";
    int num;
    char** tokens;
    cout << "Въведете текст ";
    cin.getline(text, MAX_LEN);
    tokenize(text, delims, tokens, num);
    for(int i = 0; i < num; ++i)
    {
        cout << tokens[i] << endl;                // извеждане
        delete tokens[i];        // и освобождаване на паметта
    }
    delete tokens;     // освобождаване на паметта за масива
    return 0;
}
