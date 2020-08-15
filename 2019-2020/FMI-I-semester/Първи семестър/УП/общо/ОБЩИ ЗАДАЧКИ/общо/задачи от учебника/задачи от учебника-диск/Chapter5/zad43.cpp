#include <iostream.h>

const int MAX_N = 100;

int vector [MAX_N];
int n, k;

void print()
{
    cout << "(";
    for(int i = 0; i < n-1; i++)
    {
        cout << vector[i] << ", ";
    }
    cout << vector[n-1] << ")\n";
}

void generate(int i)
{
    if(i > n)
        return; 

    // генерирани са всички вариации с повторения
    if(i == n)
    { 
        print(); 
        return;
    }

    for(int j = 0; j < k; j++)         // сред всички елементи
    {
        vector[i] = j;  // присвоява стойност на i-тия елемент
        generate(i+1);         // генерира останалите вариации
    }
}

int main()
{
    n = 5; k = 3;
    generate(0);
    return 0;
}
