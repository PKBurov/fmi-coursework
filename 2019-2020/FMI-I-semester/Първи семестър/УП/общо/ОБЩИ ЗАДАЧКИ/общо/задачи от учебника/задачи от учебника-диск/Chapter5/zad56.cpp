#include <iostream.h>

const int MAX_RINGS = 4;

// рисува един от пилоните на дъската
void printStick(int *stick)
{
    cout << endl;
    int col = 0;
    for(int row = 0; row < MAX_RINGS*2; row++)
    {
        cout << "#";
        for(col = 0; col < MAX_RINGS+1; col++)
        {
            if (row >= MAX_RINGS - stick[col] && row < MAX_RINGS + stick[col])
            {
                cout << "@";
            }
        }
        cout << endl;
    }
    cout << endl;
    char ch = '\0'; 
    while(ch == '\0')
    {
        cout << "Следващ пилон(char?)";
        cin >> ch;
    }
}

// Рисува цялата дъска. Тъй като по време на изпълнение на
// алгоритъма различните пилони (първи, втори и трети) получават
// различно значение (източник, цел, временен) е необходимо
// фунцкията да се извика веднъж преди началото на алгоритъма.
// По този начин функцията запомня кой указател за кой по ред
// пилон се отнася.
void printDesk(int* stickA, int* stickB, int* stickC)
{ 
   // запомня първоначалната подредба на
    // пилоните, тъй като тя се загубва в някои моменти
    static int *originalA = stickA,
               *originalB = stickB,
               *originalC = stickC;
    cout << "###############################################" 
         << endl;
    printStick(originalA);
    printStick(originalB);
    printStick(originalC);
    cout << "###############################################" 
         << endl;
}

// премества най-горния пул на from върху top
void moveTop(int* from, int* to)
{
    int fTop = 0,
        tTop = 0;

    // намира позицията на най-горния пул
    while(from[fTop+1] != 0)
        fTop ++;

    while(to[tTop+1] != 0)
        tTop ++;

    // премества пула
    to[tTop+1] = from[fTop];
    from[fTop] = 0;
}

// премества k пула от from на to, като използва temp
void move(int* from, int* to, int* temp, int k)
{ 
    // мести се само един пул
    if(k == 1)
    { 
        moveTop(from, to);
        printDesk(NULL, NULL, NULL);
    }
    else
    { 
        move(from, temp, to, k-1);
        move(from, to, NULL, 1);
        move(temp, to, from, k-1);
    }
}

int main()
{
    int stickA[] = {3,2,1,0,0},
        stickB[] = {0,0,0,0,0},
        stickC[] = {0,0,0,0,0};
    printDesk(stickA, stickB, stickC);
    move(stickA, stickC, stickB, 3);
    return 0;
}
