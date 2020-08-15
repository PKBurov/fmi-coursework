#include <iostream.h>

const int MAX_N = 100;
const int MAX_K = 100;

int vector[MAX_N];
int used[MAX_K];
int v[MAX_K];
int n, k;

// извеждане на вариация без повторения
void print()
{ 
    cout << "(";
    for(int i = 0; i < n-1; i++)
    {
        cout << vector[i] << ", ";
    }
    cout << vector[n-1] << ")\n";
}

// създаване и извеждане на всички вариации без повторения
void generate(int i)
{
    if(i > n) return;

    // генерирани са всички вариации без повторения
    if(i == n)
    { 
        print();
        return;
    }

    for(int j = 0; j < k; j++)          // сред всички елементи
    { 
        if(!used[j])                    // ако елементът не е използван още,
        { 
            used[j] = 1;                // се маркира за използван
            vector[i] = v[j];           // и се поставя във вектора
            generate(i+1);              // генериране на останалите елементи
            used[j] = 0;                // освобождаване на елемента
        }
    }
}

int main()
{ 
    n = 5; k = 5;
    int i;
    for(i = 0; i < k; i++)
    {
        v[i] = i+1;
    }
    generate(0);
    return 0;
}
