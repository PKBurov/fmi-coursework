#include <iostream.h>

// глобален масив, съдържащ лабиринта
bool labyrinth[8][8] = { 
    1, 0, 1, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 1, 1, 0, 1, 1, 0, 1,
    0, 0, 0, 1, 1, 1, 0, 1,
    1, 1, 1, 1, 1, 1, 0, 1,
    1, 1, 1, 1, 1, 0, 0, 1,
    1, 1, 1, 1, 1, 0, 1, 1,
    1, 1, 1, 1, 1, 0, 1, 1 
};

// Извежда пътя, записан в масива way,
// като way[2*i] е абсцисата на i-тата клетка,
// а way[2*i+1] е ординатата й
void printWay(int *way, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        cout << "(" << way[2*i] << "," 
             << way[2*i+1] << ")->";
    }
    cout << "(" << way[2*(n-1)] << "," 
         << way[2*n-1] << ")"<<endl;
}

// Сравнява новооткрития път way с текущия най-къс път minWay
void registerWay(int *way, int n, int* minWay, int& minWayN)
{
    if(minWayN == -1 || minWayN > n)
    {
        for( minWayN = 0; minWayN < n; minWayN++)
        { 
            minWay[2*minWayN] = way[2*minWayN];
            minWay[2*minWayN+1] = way[2*minWayN+1];
        }
    }
}

// Рекурсивна процедура, намираща всички
// пътища от клетка (x,y) до клетка (7,7)
// crrWay е текущият път, а l е дължината му
// minWay е минималният път, а minWayN е дължината му
void way(int x, int y, int *crrWay, int l, int* minWay, int& minWayN)
{
    crrWay[2*l] = x;
    crrWay[2*l+1] = y;

    // Клетката е извън лабиринта.
    if( x < 0 || y < 0 || x > 7 || y > 7 )
        return;

    // Намерен е път.
    // сравняване на този път с текущия минимален път
    if(x == 7 && y == 7)
    {
        registerWay(crrWay, l+1, minWay, minWayN);
        return;
    }

    // Клетката е непроходима.
    if(!labyrinth[x][y])
        return;

    // Клетката е проходима.
    // С цел продотвратяване на зацикляне,
    // клетката се маркира като непороходима.
    labyrinth[x][y] = 0;

    // Рекурсивни обръщения към всеки от четирите съседа
    way(x+1, y, crrWay, l+1, minWay, minWayN);
    way(x, y+1, crrWay, l+1, minWay, minWayN);
    way(x-1, y, crrWay, l+1, minWay, minWayN);
    way(x, y-1, crrWay, l+1, minWay, minWayN);
    // връщане назад
    labyrinth[x][y] = 1;
}

int main()
{
    int crrWay[128] = {0},
        minWay[128] = {0},
        minWayN = -1;
    way(0, 0, crrWay, 0, minWay, minWayN);
    printWay(minWay, minWayN);
    return 0;
}
