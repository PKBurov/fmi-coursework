#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cstring>

// функция, която разменя стойностите на две целочислени променливи
inline void swap(int& first, int& second)
{
    // cout << "This is NOT the template function!\n";

    int temp = first;
    first = second;
    second = temp;
}

template<typename T>
inline void swap(T& first, T& second)
{
    // cout << "This is the TEMPLATE function!\n";

    // ограничения: ако Т е клас, трябва да има дефинирани
    // копиращ конструктор и операция за присвояване
    T temp = first;
    first = second;
    second = temp;
}

// функция, която връща минималния от два елемент
inline int min(int first, int second)
{
    if(first < second)
        return first;

    return second;
}

template <typename T>
inline T min(T first, T second)
{
    // за типа Т трябва да има предефиниран копиращ конструктор,
    // параметрите се предават и връщат по стойност, както и
    // предефинирана операция за сравнение <
    if(first < second)
        return first;

    return second;
}

// шаблон на функцията, в който са параметризирани
// както аргументите на функцията, така и резултата
// пред всеки от параметрите трябва да се постави typename
template <typename ResT, typename FirT, typename SecT>
// ако променим мястото на параметъра ResT,
// при извикването на функцията ще трябва да укажем явно
// всички преди него...
inline ResT max(FirT first, SecT second)
{
    // за типа Т трябва да има предефиниран копиращ конструктор,
    // параметрите се предават и връщат по стойност, както и
    // предефинирана операция за сравнение >
    if(first > second)
        return first;

    return second;
}

// предефиниране на шаблона на функцията за конкретен тип
inline const char* min(const char* first, const char* second)
{
    if(strcmp(first, second) < 0)
        return first;

    return second;
}

// сортиране по метода на мехурчето
inline void bubbleSort(int array[], int size)
{
    int right = size - 2;

    while(right > 0)
    {
        int lastSwapIndex = 0;

        for(int i = 0; i <= size - 2; ++i)
        {
            if(array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                lastSwapIndex = i;
            }
        }

        right = lastSwapIndex;
    }
}

template <typename T>
inline void bubbleSort(T array[], int size)
{
    int right = size - 2;

    while(right > 0)
    {
        int lastSwapIndex = 0;

        for(int i = 0; i <= size - 2; ++i)
        {
            // още едно допълнително ограничение към типа T,
            // да има предефиниран operator >
            if(array[i] > array[i + 1])
            {
                // трябва да се извика шаблонната функция
                swap<T>(array[i], array[i + 1]);
                lastSwapIndex = i;
            }
        }

        right = lastSwapIndex;
    }
}

void testSwap()
{
    int first = 1, second = 2;

    cout << "Before: " << first << " " << second << endl;
    // ако се пропусне специализацията <int>, се извиква нешаблонната функция
    swap<int>(first, second);
    cout << "After: " << first << " " << second << endl;

    const char* strFirst = "First", *strSecond = "Second";
    cout << "Before: " << strFirst << " " << strSecond << endl;
    swap(strFirst, strSecond);
    cout << "After: " << strFirst << " " << strSecond << endl;
}

void testBubbleSort()
{
    int array[] = {5, 1, 4, 2, 8, 3};
    int size = sizeof(array)/ sizeof(int);

    cout << "NOT Sorted Array: ";
    for( int i = 0; i <= size - 1; ++i)
    {
        cout << array[i] << " ";
    }

    bubbleSort<int>(array,size);

    cout << "\nSorted Array: ";
    for( int i = 0; i <= size - 1; ++i)
    {
        cout << array[i] << " ";
    }
}

void testMin()
{
    int first = 1, second = 2;

    cout << "\nBetween " << first << " and " << second << ", the min elem is: \n"
         << "Non-template function: " << min(first, second)
         << "\nTemplate function: " << min<int>(first, second);

    cout <<"\n\nUse template specalization for char*...\n";

    const char* strFirst = "First", *strSecond = "Second";;
    cout << "Between " << strFirst << " and " << strSecond << ", the min elem is: "
         << "\nTemplate function: " << min(strFirst, strSecond);

    cout << "\n\nAttempt to call the function, using parameters with different type...\n";
    double third = .05;
    cout << "\nBetween (int)" << first << " and (double)" << third << ", the min elem is: \n"
         << "\nNon-template function: " << min(first, third)
         << ", the second input parameter is cast to int!\n"
         << "\nIf only the template function was defined: " << min(static_cast<double>(first), third)
         << "\nSpecifying explicitly the type of T: " << min<double>(first, third);
}

void testMax()
{
    int first = 1;
    double second = 1.5;

    cout << "\nCompare the elements " << first << " and " << second << endl;
    // типът на резултата не може да бъде определен при извикването на функцията,
    // трябва да бъде указан явно..
    cout << "The max elem is " << max<double>(first, second) << endl;
}

int main()
{
    testSwap();
    testBubbleSort();
    testMin();
    testMax();

    return 0;
}
