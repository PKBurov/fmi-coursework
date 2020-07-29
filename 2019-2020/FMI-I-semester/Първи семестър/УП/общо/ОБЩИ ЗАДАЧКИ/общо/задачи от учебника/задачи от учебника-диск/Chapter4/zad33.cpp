#include <stdlib.h>
#include <string.h>

//À
int StringCompareNotSensitive(const char* first,
                              const char* second)
{ 
    char fSym;
    char sSym;
    do
    { 
        fSym = *(first++);
        if(fSym >= 'A' && fSym <= 'Z')
        {
            fSym = fSym - 'A' + 'a';
        }
        else if(fSym >= 'À' && fSym <= 'ß') 
        {
            fSym = fSym - 'À' + 'à';
        }

        sSym = *(second++);
        if(sSym >= 'A' && sSym <= 'Z')
        {
            sSym = sSym - 'A' + 'a';
        }
        else if(sSym >= 'À' && sSym <= 'ß') 
        {
            sSym = sSym - 'À' + 'à';
        }

        if(sSym != fSym)
        {
            return fSym - sSym;
        }
    } while(sSym != '\0');
    return 0;
}


//Á
void TrimLeft(char* text, const char* tokens)
{ 
    char* current = text;
    while(*current)
    { 
        if(!strchr(tokens, *current))
            break;
        current++;
    }
    if(current > text)
    {
        strcpy(text, current);
    }
}

//Â
void TrimRight(char* text, const char* tokens)
{ 
    char* current = text + strlen(text) - 1;
    while(current > text)
    { 
        if(!strchr(tokens, *current))
            break;
        current--;
    }
    *(current + 1) = '\0';
}

//Ã
void Trim(char* text, const char* tokens)
{
    TrimLeft(text, tokens);
    TrimRight(text, tokens);
}

//Ä
void RemoveToken(char* text, const char* tokens)
{ 
    char* target = text;
    char sym;
    while(sym = *text)
    {
        if(!strchr(tokens, sym))
        {
            *target = sym;
            target++;
        }
        text++;
    }
    *target = '\0';
}


//Å
void ToUpper(char* text)
{ 
    char sym;
    while(sym = *text)
    { 
        if(sym >= 'a' && sym <= 'z')
        {
            *text = sym - 'a' + 'A';
        }
        else if(sym >= 'à' && sym <= 'ÿ')
        {
            *text = sym - 'à' + 'À';
        }
        text++;
    }
}


//Æ
void ToLower(char* text)
{ 
    char sym;
    while(sym = *text)
    { 
        if(sym >= 'A' && sym <= 'Z')
        {
            *text = sym - 'A' + 'a';
        }
        else if(sym >= 'À' && sym <= 'ß')
        {
            *text = sym - 'À' + 'à';
        }
        text++;
    }
}
