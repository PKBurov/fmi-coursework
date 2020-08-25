#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>

/*
Група 3: За всеки елемент на случайно инициализиран с числа от интервала [-5; 5] масив от 10 елемента
да се изведе сумата на елемента с двата следващи го.
Първо да се изведе масива. Всеки елемент от изхода да е отделен от другия с празно място.*/

using namespace std;

const int ARRAY_LENGTH = 10;
const int BLUR_RADIUS = 5;
const int RANGE_SIZE = 2 * BLUR_RADIUS + 1;

int main()
{
    srand(time(NULL));
    int a [ARRAY_LENGTH];
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        a[i] = rand() % RANGE_SIZE - BLUR_RADIUS;
    }

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        int nextIndex = (i + 1) % ARRAY_LENGTH;
        int postNextIndex = (i + 2) % ARRAY_LENGTH;
        int sum = a[i] + a[nextIndex] + a[postNextIndex];
        cout << sum << ' ';
    }
    cout << endl;
}
