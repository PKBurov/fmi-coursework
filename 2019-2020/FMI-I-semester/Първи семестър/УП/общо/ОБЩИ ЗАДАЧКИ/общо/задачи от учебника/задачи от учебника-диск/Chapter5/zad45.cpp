#include <iostream.h>

const int MAX_N = 100;
const int MAX_K = 100;

int vector[MAX_N];
int v[MAX_K];
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

void generate(int i, int j)
{
    if(i > n) return;

    if(i == n)
    { 
        print();
        return;
    }                       // генерирани са всички комбинации

    for(; j < k; j++)       // Сред всички оставащи елементи
    { 
        vector[i] = v[j];	  // се задава елемент от оставащите
        generate(i+1, j+1); // и се генерират следващите комбинации
    }
}

int main()
{ 
    n = 5; k = 5;
    int i;
    for(i = 0; i < k; i++)
        v[i] = i+1;
    generate(0, 0);
    return 0;
}

