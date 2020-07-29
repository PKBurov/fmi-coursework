#include <iostream.h>

// връща първия символ (елемент) на низа x;
char car(const char* x) 
{ 
    return x[0];
}

// връща останалата част от низа x след
// отделянето на първия елемент на низа x;
char* cdr(char* x)
{ 
    return x+1;
}

void number_of_coach(char* x, int n, int m)
{
    int l = 0;
    while (*x)
    {
        char p = car(x);
        if(p != 'B' && p != 'R')
        {
            l++;
            if(l >= n && l <= m)
            {
                cout << "N " << l << " ";
                switch(p)
                {
                case 'L': cout << "Локомотив\n";
                    break;
                case 'O': cout << "Общ пътнически вагон\n";
                    break;
                case 'K': cout << "Вагон с купета\n";
                    break;
                case 'P': cout << "Туристически вагон\n";
                    break;
                case 'M': cout << "Вагон първа класа\n";
                    break;
                case 'S': cout << "Спален вагон\n";
                }
            }
        }
        x = cdr(x);
    }
}
