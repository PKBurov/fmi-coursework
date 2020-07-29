#include <string.h>
#include <iostream.h>

bool cmp_strings(char a[][6][101])
{
    char * resultRight = new char,
         * resultBottom = new char,
         * tmp = 0;
    resultRight[0] = 0;
    resultBottom[0] = 0;

    int i, j;
    for(i = 0; i < 5; i++)
    {
        for(j = i+1; j < 6; j++)
        {
            tmp = new char [strlen(resultRight) + strlen(a[i][j]) + 1];
            strcpy(tmp, resultRight);
            strcat(tmp, a[i][j]);
            delete resultRight;
            resultRight = tmp;

            tmp = new char [strlen(resultBottom) + strlen(a[j][i]) + 1];
            strcpy(tmp, resultBottom);
            strcat(tmp, a[j][i]);
            delete resultBottom;
            resultBottom = tmp;
        }
    }

    cout << resultRight << endl 
        << resultBottom << endl;

    bool b = strcmp(resultRight, resultBottom) < 0;
    delete resultRight;
    delete resultBottom;
    return b;
}
