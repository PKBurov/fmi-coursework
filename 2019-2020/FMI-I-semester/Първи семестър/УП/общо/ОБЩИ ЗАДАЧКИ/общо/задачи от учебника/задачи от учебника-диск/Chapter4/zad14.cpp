#include <iostream.h>

const int MAX_SIZE = 100;
double array[MAX_SIZE];

int InputArray()
{
    int size;
    do
    {
        cout << "Въведете размер на масива между 1 и "
            << MAX_SIZE << endl;
        cin >> size;
    } while(size <= 0 || size > MAX_SIZE);

    for(int i = 0; i < size; i++)
    { 
        cout << "array[" << i << "]= ";
        cin >> array[i];
    }
    return size;
}

void FindDuplicate(int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        int foundBefore = 0; // дали array[i] се е срещал вече
        int foundAfter = 0;  // дали array[i] се среща напред
        for(j = 0; j < i; j++)
        {
            if(array[j] == array[i])
            {
                foundBefore = 1;
                break;
            }
        }

        for(j = i + 1; j < size; j++)
        {
            if(array[j] == array[i])
            {
                foundAfter = 1;
                break;
            }
        }
        if(foundAfter && (!foundBefore))
        {
            cout << array[i] << endl;
        }
    }
}

int main()
{ 
    int size = InputArray();
    FindDuplicate(size);
    return 0;
} 
