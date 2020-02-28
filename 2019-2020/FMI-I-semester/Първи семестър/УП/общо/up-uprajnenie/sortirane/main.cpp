#include <iostream>

using namespace std;

int main()
{
    //метод за пряката селекция на съртиране-алгоритъм за сортиране-намираш кой е най-малкия елемент и го записваме на 0 позиция, 1-ва и т.н
    int curr_size=5;
    int arr[curr_size];
    for(int i=0; i<curr_size;i++)
    {
    cin>>arr[i];
    }

    for(int i=0; i<curr_size-1;i++)
    {
        int min=i;
        for(int j=i+1;j<curr_size;j++ )
          {
              if(arr[min]>arr[j])
            {
            min=j;
            }

        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;

          }




    }

    for(int i=0;i<curr_size;i++)
    {
    cout<<arr[i]<<" ";
    }


    return 0;
}
