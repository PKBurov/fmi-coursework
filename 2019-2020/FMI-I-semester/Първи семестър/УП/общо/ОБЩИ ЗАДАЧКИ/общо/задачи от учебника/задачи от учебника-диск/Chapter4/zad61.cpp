#include <iostream.h>
#include <iomanip.h>

const int MAX_SIZE = 10;

// въвеждане на дъгите на графа
void ReadMatrix(int k, int a[][2])
{
    for(int i = 0; i < k; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
}

// извеждане на дъгите на графа
void WriteMatrix(int k, int a[][2])
{
    for(int i = 0; i < k; i++)
    {
        cout << setw(7) << a[i][0]
        << setw(7) << a[i][1] << endl;
    }
}

// търсене на прост път от връх S до връх P на графа
void Way(int a[][2], int m, int S, int P)
{
    int Used[MAX_SIZE] = {0, },
        Stack[MAX_SIZE],
        T = S,
        k = 0,
        i, C;

    // построяване на частично решение
    Used[T] = 1;
    Stack[k] = T;
    k++;

    // проверяване дали това частично решение е общо
    while(T != P)
    {
        // частичното решение не е общо
        int i = -1;
        do
        { // търсене на продължение на частичното решение
            i++;
            if(a[i][0] == T)
            { 
                C = a[i][1];
                if(Used[C] == 0)
                { 
                    // извършва се продължение на
                    // частичното решение
                    T = C;
                    Used[T] = 1;
                    Stack[k] = T;
                    k++;

                    // проверка дали частичното решение е общо
                    if(T == P)
                    {
                        for(i = 0; i < k; i++)
                        {
                            cout << Stack[i] << " ";
                        }
                        cout << endl;
                        return;
                    }
                    else 
                    {
                        i = -1;
                    }
                }
            }
        } while(i < m-1);

        if(T == S) 
        {
            cout << "Няма прост път.\n"; 
            return;
        }
        else
        { 
            // връщане назад
            k--;
            T = Stack[k-1];
        }
    }
    // намерено е решение и то се извежда
    for(i=0; i < k; i++)
    {
        cout << Stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    int A[MAX_SIZE][2];
    int m;
    cout << "m= "; 
    cin >> m;

    ReadMatrix(m, A);
    WriteMatrix(m, A); 
    cout << endl;
    
    cout << "Начален връх: ";
    int beg; 
    cin >> beg;
    
    cout << "Краен връх: ";
    int end; 
    cin >> end;

    Way(A, m, beg, end);
    return 0;
}
