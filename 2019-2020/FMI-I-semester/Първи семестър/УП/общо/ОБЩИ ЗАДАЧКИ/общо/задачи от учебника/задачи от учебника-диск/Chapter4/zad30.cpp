#include <iostream.h>
#include <string.h>

const int MAX_SIZE = 100;

// помощна фунцкция, добавяща към края на низа to
// символите от низа from, които не се срещат в to
// Предполага се, че в to има достатъчно място
void addUnique(char* to, const char* from)
{ // дължините на from и to и индекси
    int l1 = strlen(from),
        l2 = strlen(to),
        i = 0,
        j = 0;
    for(i = 0; i < l1; i++)
    { 
        j = 0;
        //търси се i-тият символ на from в to
        while(j < l2 && to[j] != from[i])
            j++;
        if(j == l2)
        { 
            to[j] = from[i];
            j++;
            to[j] = '\0';
            l2++;
        }
    }
}

// обединява s1 и s2
char* stringUnion(const char* s1, const char* s2)
{ 
    char* u = new char[strlen(s1) + strlen(s2)+1];
    u[0] = '\0';
    addUnique(u,s1);
    addUnique(u,s2);
    return u;
}

int main()
{ 
    char s1[MAX_SIZE], s2[MAX_SIZE];
    cin >> s1 >> s2;
    cout << stringUnion(s1, s2) << endl;
    return 0;
}
