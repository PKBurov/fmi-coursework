#include <iostream>

using namespace std;

int main()
{
    const int SIZE=100;
    int n,x;
    int array[SIZE];
    int br=1,max=0;

    cout<<"n=";
    cin>>n;

    for(int i=0;i<n;i++)
    {
    cin>>array[i];
    }

    for(int i=0;i<n;i++)
        {
            if(array[i]<=array[i+1])
            {
            br++;
            }
            else
            {
            br=0;
            }
        }


        cout<<br<<endl;

    return 0;
}
