#include <iostream.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *students[] = {"100000 Иван",
                        "200000 Петър",
                        "300000 Георги",
                        "400000 Мария",
                        "500000 Пенка"},
        *grades[]    = {"100000 6.00",
                        "150000 3.00",
                        "300000 5.50",
                        "500000 4.50",
                        "600000 2.00"};
    int nStudents = 5,      // брой елементи на масива students
        nGrades = 5,		// брой елементи на масива grades
        iStudents = 0,	    // индекс за обхождане на масива students
        iGrades = 0;        // индекс за обхождане на масива grades
    char fn1[7], fn2[7];

    while(iStudents < nStudents && iGrades < nGrades)
    {
        strncpy(fn1, students[iStudents], 6);
        strncpy(fn2, grades[iGrades], 6);
        fn1[6] = fn2[6] = 0;
        if(strcmp(fn1, fn2) == 0)
        { 
            double min = atof(grades[iGrades]+7) + 1;
            if(6.0 < min)
            {
                min = 6.0;
            }
            cout << students[iStudents] + 7 << " " 
                 << min << endl;
            iStudents++;
            iGrades++;
        }
        else
        {
            if(strcmp(fn1, fn2) < 0)
            {
                iStudents++;
            }
            else
            {
                iGrades++;
            }
        }
    }

    return 0;
}
