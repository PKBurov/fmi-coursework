/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Silvia Ivanova
 * @idnumber 61999
 * @task 5
 * @compiler GCC
 *
 */


#include <iostream>
#include <cmath>

using namespace std;

double functionTotal(double r)
{
if(r>=0 && r<=1) return 60;
if(r>1 && r<9) return 20;
if(r==9) return 0;
if(r==64) return 0;
if(r>9 && r<=64) return 10;
if(r>64) return 0;
}

int main()
{
    double Ax,Ay,x,y, r0, r1,realAx, realAy, weight, height;
    cin>>Ax>>Ay>>x>>y;

	realAx = Ax + x;
	realAy = Ay + y;



    if(x==0 && y==0)
    {
        r0=pow(Ax,2)+pow(Ay,2);
        cout<<functionTotal(r0)<<"\n";

    }
    else
    {
        r1=pow(realAx,2)+pow(realAx,2);
        cout<<functionTotal(r1)<<"\n";
    }


    return 0;
}

