#include <iostream.h>

enum sign
{
    ADD,
    SUBTR,
    MULT,
    PART
};

int main()
{
    cout << "Въведете стойност на m (m>0): ";
    int m;
    cin >> m;

    cout << "Въведете стойност на n (n>0): ";
    int n;
    cin >> n;

    cout << "Въведете стойност на p (p>0): ";
    int p;
    cin >> p;

    cout << "Въведете стойност на q (q>0): ";
    int q;
    cin >> q;

    cout << "Въведете стойност на a: ";
    int a;
    cin >> a;

    for(sign op1 = ADD; op1 <= PART; op1 = (sign)(op1+1))
    {
        for(sign op2 = ADD; op2 <= PART; op2 = (sign)(op2+1))
        {
            for(sign op3 = ADD; op3 <= PART; op3 = (sign)(op3+1))
            {
                int s; 
                switch(op1)
                { 
                case ADD:  s = m + n; break;
                case SUBTR:s = m - n; break;
                case MULT: s = m * n; break;
                case PART: s = m / n;
                }

                switch(op2)
                { 
                case ADD:  s = s + p; break;
                case SUBTR:s = s - p; break;
                case MULT: s = s * p; break;
                case PART: s = s / p; 
                }

                switch(op3)
                { 
                case ADD:  s = s + q; break;
                case SUBTR:s = s - q; break;
                case MULT: s = s * q; break;
                case PART: s = s / q;
                }

                if(s == a) 
                { 
                    switch(op1)
                    { 
                    case ADD:  cout << "(+, "; break;
                    case SUBTR:cout << "(-, "; break;
                    case MULT: cout << "(*, "; break;
                    case PART: cout << "(/, ";
                    }

                    switch(op2)
                    { 
                    case ADD:  cout << "+, "; break;
                    case SUBTR:cout << "-, "; break;
                    case MULT: cout << "*, "; break;
                    case PART: cout << "/, ";
                    }

                    switch(op3)
                    { 
                    case ADD:  cout << "+)\n"; break;
                    case SUBTR:cout << "-)\n"; break;
                    case MULT: cout << "*)\n"; break;
                    case PART: cout << "/)\n";
                    }
                }
            }
        }
    }
    return 0;
} 
