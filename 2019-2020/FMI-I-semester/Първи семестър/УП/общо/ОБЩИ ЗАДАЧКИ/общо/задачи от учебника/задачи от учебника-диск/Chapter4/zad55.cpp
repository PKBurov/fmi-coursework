#include <iostream.h>
#include <iomanip.h>

const int MAX_SIZE = 20;

void sortasc(int arr[], int n)
{
    int i, j, mini;

    for(i = 0; i < n-1; i++)
    {
        mini = i;
        for(j = i+1; j < n; j++)
        {
            if(arr[mini] > arr[j])
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

void sortdesc(int arr[], int n)
{
    int i, j, maxi;
    for(i = 0; i < n-1; i++)
    {
        maxi = i;
        for(j = i+1; j < n; j++)
        {
            if(arr[maxi] < arr[j])
            {
                maxi = j;
            }
        }
        if(maxi != i)
        {
            int t = arr[maxi];
            arr[maxi] = arr[i];
            arr[i] = t;
        }
    }
}

void print(int arr[][MAX_SIZE], int n, int m)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cout << setw(5) << arr[i][j];
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
            sortdesc(arr[i], m);
        else
            sortasc(arr[i], m);
    }
    print(arr, n, m);
    return 0;
}
