#include <iostream.h>

const int MAX_SIZE = 20;

void sort(int arr[], int n, bool (*op)(int, int))
{
    int i, j, mini;
    for(i = 0; i < n-1; i++)
    { 
        mini = i;
        for(j = i+1; j < n; j++)
        {
            if(op(arr[mini], arr[j]))
            {
                mini = j;
            }
        }

        if(mini != i)
        { 
            int t = arr[mini];
            arr[mini] = arr[i];
            arr[i] = t;
        }
    }
}

bool max(int x, int y)
{ 
    return x > y;
}

bool min(int x, int y)
{ 
    return x < y;
}

void print(int arr[][MAX_SIZE], int n, int m)
{ 
    int i, j;
    for(i = 0; i < n; i++)
    { 
        for(j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{ 
    int arr[MAX_SIZE][MAX_SIZE] =
    { {2, 14, 5, 2, 3, 5},
      {2, 1, 4, 5, 2, 4},
      {6, 5, 3, 4, 2, 5},
      {4, 5, 2, 6, 4, 6}
    };
    int n = 4, m = 6, i;
    for(i = 0; i < n; i++)
    {
        if(i % 2)
        {
            sort(arr[i], m, max);
        }
        else
        {
            sort(arr[i], m, min);
        }
    }
    print(arr, n, m);
    return 0;
}
