/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 6
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main()
{
	int Ax, Ay, b, a;
	int Bx, By, b1, a1;
	double S = 0,m,n;

	cin>> Ax>> Ay>> b>> a;
	cin>> Bx>> By>> b1>>a1;

	if (Ax + a < Bx && Ay + b < By)
	{
		cout << S << "\n";
		return 0;
	}

	if (Bx + a1 < Ax && By + b < Ay)
	{
		cout << S << "\n";
		return 0;
	}

	if (Ax < Bx && Bx < Ax + a && Ay + b<By)
	{
		cout << S << "\n";
		return 0;
	}
	if(Bx + a1<Ax && Bx<Ax)
	{
		cout << S << "\n";
		return 0;
	}

	if (Ax < Bx && Bx < Ax + a && Ay+b>By && Bx+a1>=Ax+a)
	{
		m = fabs(Ax + a - Bx);
		n = fabs(By + b1 - Ay);
		S = m*n;
		cout << S << "F\n";
		return 0;
	}
	
	if (Ax < Bx && Bx < Ax + a && Ay + b>By && Bx + a1 < Ax + a && (Ay + b) <(By + b1))
	{
		m = a1;
		n = fabs(Ay + b - By);
		S = m*n;
		cout << S << "\n";
		return 0;
	}

	

	if (Ax == Bx)
	{
		if (Ax + a < Bx + a1)
		{
			m = a;
			n = b - By;
			S = m*n;
			cout << S << "\n";
			return 0;
		}
		else
		{
			m = a1;
			n= b - By;
		}
	}
	
	if (a < a1 && b < b1 && Ax < Bx)
	{
		S = a1*b1;
		cout << S << "\n";
		return 0;
	}
	if (a > a1 && b > b1 && Ax > Bx  )
	{
		S = a*b;
		cout << S << "\n";
		return 0;
	}

	if (Ax > Bx && Bx +a1> Ax && Ay<By+b && Bx+a1<Ax+a)
	{
		m = fabs(Bx + a1 - Ax);
		n = fabs(Ay + b - By);
		S = m*n;
		cout << S << "\n";
		return 0;
	}

	if (Ax > Bx && (Bx + a1) > (Ax + a))
	{
		m = fabs(Ax + a - Bx);
		n = fabs(Ay + b - By);
		S = m*n;
		cout << S << "\n";
		return 0;
	}

	if (Ax < Bx && (Bx + a1) < (Ax + a) && (Ay + b) > (By + b1))
	{
		S = a1*b1;
		cout << S << "\n";
	}

	return 0;
}

