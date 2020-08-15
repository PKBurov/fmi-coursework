#include <iostream.h>
#include <math.h>
#include <assert.h>

//============================
// Функции за симулация на    
// монохромен дисплей         
//============================
// Булева матрица за симулация на растерен дисплей.
// Елементите на матрицата съответстват на "пикселите"
// на монохромен дисплей 80 реда по 80 колони.
bool screen[80][80] = {false};

// Текуща позиция на молива върху дисплея
double penX = 0, penY = 0;

// Премества позицията на молива
void gotoXY(double x, double y)
{
    penX = x;
    penY = y;
}

// Включва/изключва пиксел на дадена позиция
void setPixel(double x, double y, bool on = true)
{
    assert(penX < 80 && penY < 80);
    screen[(int)y][(int)x] = on;
}

// помощна функция
int iabs(double x)
{
    return abs((int)(x));
}

// Чертае линия от текущата позиция на молива
// до позиция (x,y) и премества молива в нея
void lineTo(double x, double y)
{ 
    double initialPenX = penX,
           initialPenY = penY;

    setPixel(penX,penY);
    if(x != penX)
    {
        for( ;iabs(penX - x) > 0; penX += (x > penX?1:-1))
        { 
            penY = initialPenY + (y-initialPenY)*
                  (penX-initialPenX)/(x-initialPenX);
            setPixel(penX, penY);
        }
    }
    else
    {
        for( ;iabs(penY - y) > 0; penY += (y > penY?1:-1))
        {
            setPixel(penX, penY);
        }
    }
}

// Чертае линия с отместване отностно текущия
// връх на молива
void lineRel(double dx, double dy)
{ 
    lineTo(penX + dx, penY + dy);
}

// Чертае линия наляво от текущата позиция
void left(int l)
{ 
    lineRel(-l,0);
}

// Чертае линия надясно от текущата позиция
void right(int l)
{ 
    lineRel(l,0);
}

// Чертае линия нагоре от текущата позиция
void up(int l)
{ 
    lineRel(0,-l);
}

// Чертае линия надолу от текущата позиция
void down(int l)
{ 
    lineRel(0,l);
}

// Извежда "екрана" на конзолата
void printScreen()
{ 
    int i = 0,
        j = 0;
    cout << endl;

    // при някои среди за кривата от 1,2 и 3-ти ред е
    // подходящо ограничението за параметъра i да се
    // замени с 23, а за кривата от 4-ти ред,
    // изображението на кривата да се раздели на 3 части
    for(i = 0; i < 80; i++)
    {
        for(j = 0; j < 80; j++)
        {
            cout << (screen[i][j]?'@':' ');
        }
    }
}

//=================================================
// Функции за рисуване на
// кривата на Хилберт
//==================================================
void hilbertA(int level, double dist);
void hilbertB(int level, double dist);
void hilbertC(int level, double dist);
void hilbertD(int level, double dist);

void hilbert(int level)
{ 
    double currentDistance = 3;
    for( ;level >0; level--)
    { 
        gotoXY(currentDistance / 2, currentDistance / 2);
        hilbertA(level, currentDistance);
        currentDistance /= 2;
    }
}

void hilbertA(int level, double dist)
{
    // дъно на рекурсията
    if(level == 0)
        return;	

    hilbertB(level-1, dist); down((int)dist);
    hilbertA(level-1, dist); right((int)dist);
    hilbertA(level-1, dist); up((int)dist);
    hilbertC(level-1, dist); 
}

void hilbertB(int level, double dist)
{
    // дъно на рекурсията
    if(level == 0)
        return;

    hilbertA(level-1, dist); right((int)dist);
    hilbertB(level-1, dist); down((int)dist);
    hilbertB(level-1, dist); left((int)dist);
    hilbertD(level-1, dist);
}

void hilbertC(int level, double dist)
{
    // дъно на рекурсията
    if(level == 0)
        return;	

    hilbertD(level-1, dist); left((int)dist);
    hilbertC(level-1, dist); up((int)dist);
    hilbertC(level-1, dist); right((int)dist);
    hilbertA(level-1, dist);
}

void hilbertD(int level, double dist)
{
    // дъно на рекурсията
    if(level == 0)
        return;

    hilbertC(level-1, dist); up((int)dist);
    hilbertD(level-1, dist); left((int)dist);
    hilbertD(level-1, dist); down((int)dist);
    hilbertB(level-1, dist);
}

int main()
{
    hilbert(3);                 // за крива от трети ред
    printScreen();
    return 0;
}
