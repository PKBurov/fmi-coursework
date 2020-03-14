#include <iostream>

using namespace std;

int main()
{
    const int SIZE=30;
    int n,x;
    int array[SIZE];
    int br=1,check;

    cout<<"n=";
    cin>>n;

    for(int i=0;i<n;i++)
    {
    cin>>array[i];
    }

    for(int i=0;i<n;i++)
        {
            if(array[i]<=array[n-i])
            {
            br++;
            }
                else
                {
                br=0;
                }
        }


            check=n/2;
            if(check==br)
                  {
                      cout<<"SYMETRIC"<<endl;
                  }
                    else
                         {
                      cout<<"NOT SYMETRIC"<<endl;
                  }
    return 0;
}
