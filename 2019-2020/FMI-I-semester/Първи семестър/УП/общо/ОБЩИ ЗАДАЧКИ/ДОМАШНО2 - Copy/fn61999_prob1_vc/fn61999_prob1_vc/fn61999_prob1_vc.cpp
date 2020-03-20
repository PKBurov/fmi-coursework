/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 1
* @compiler VC
*
*/

#include<iostream>
#include<cmath>
#include <iomanip>   

using namespace std;

double distance(double x1, double y1, double x2, double y2)
{


	double a = (x2-x1)*(x2-x1);
	double b = (y2-y1)*(y2-y1);

	return sqrt(a+b);
}


double function(double x)
{
	double rezult;
	double pi = 3.14;

	rezult = (0.5*pi*x + x)/2;
	return rezult;
}

bool check(double x, double y)
{
	if (x <= 5 && x >= -5 && y <= 2 && y >= -2)
		return true;
	else
		return false;
}

int quadrant(double a, double b)
{
	int first = 1, second = 2, third = 3, fourth = 4;
	if (a > 0 && b > 0)
		return first;

	if (a < 0 && b>0)
		return second;

	if (a < 0 && b < 0)
		return third;

	if (a > 0 && b < 0)
		return fourth;

	if (a == 0 || b == 0)
		return 0;
}

int main()
{
	unsigned int n;
	cin >> n;
	double arr[100];
	double s = 0;
	double x;
	const double tangens = 0.4;
	double tangensL;
	double newX=0, newY=0;

	if (n == 0)
	{
		cout << s << '\n';
		return 0;
	}

	
	for (int j = 0; j < n*2; j++)
	{
		cin >> arr[j];

	}
	double Ax, Ay, Bx, By;
	for (int i = 0; i < n * 2 - 2; i=i+2)
	{
		 Ax = arr[i];
		 Ay= arr[i+1];
		 Bx = arr[i+2];
		 By = arr[i + 3];

		 if (check(Ax, Ay) == 0 && check(Bx, By) == 0 )
		 {
			 x = 0;
			 s += function(x);
		 }


		 //A, B in rectangle
		 if (check(Ax, Ay) == 1 && check(Bx, By) == 1)
		 {
			 x= distance(Ax, Ay, Bx, By);
			 s += function(x);
		 }


		 //A in rectangle
		 if (check(Ax, Ay) == 1 && check(Bx, By) == 0)
		 {
			
			 if (Ax == Bx)
			 {
				 if (quadrant(Ax, Ay) == 1 || quadrant(Ax, Ay) == 2)
				 {
					 x = distance(Ax, Ay, Bx, 2);
					 s += function(x);
				 }

				 if (quadrant(Ax, Ay) == 4 || quadrant(Ax, Ay) == 3)
				 {
					 x = distance(Ax, Ay, Bx, -2);
					 s += function(x);
				 }

				 if (quadrant(Bx,By) == 0)
				 {
					 if (By > 0)
					 {
						 x = distance(Ax, Ay, Bx, 2);
						 s += function(x);	
					 }
					 else
					 {
						 x = distance(Ax, Ay, Bx, -2);
						 s += function(x);
					 }
				 }
			 }

			 if (Ay == By)
			 {
				 if (quadrant(Ax, Ay) == 1 || quadrant(Ax, Ay) == 4)
				 {
					 x = distance(Ax, Ay, 5, By);
					 s += function(x);	 
				 }

				 if (quadrant(Ax, Ay) == 2 || quadrant(Ax, Ay) == 3)
				 {
					 x= distance(Ax, Ay, -5, By);
					 s += function(x);
					
				 }

				 if (quadrant(Bx, By) == 0)
				 {
					 if (Bx > 0)
					 {
						 x = distance(Ax, Ay, 5, By); 
						 s += function(x);
					 }
					 else
					 {
						 x = distance(Ax, Ay, -5, By); 
						 s += function(x);	
					 }
				 }
			 }

			 tangensL = fabs(Ay) / fabs(Ax);

			 if (tangens == tangensL)
			 {
				 if (quadrant(Ax, Ay) == 1)
				 {
					 newX = 5;
					 newY = 2;
				 }

				 if (quadrant(Ax, Ay) == 2)
				 {
					 newX = -5;
					 newY = 2;
				 }

				 if (quadrant(Ax, Ay) == 3)
				 {
					 newX = -5;
					 newY = -2;
				 }

				 if (quadrant(Ax, Ay) == 4)
				 {
					 newX = 5;
					 newY = -2;
				 }
			 }

			 if (quadrant(Ax, Ay) == 1 || quadrant(Ax, Ay) == 4)
			 {
				 if (tangensL < tangens)
				 {
					 newX = 5;
					 newY = (newX - Ax)*(By - Ay) / (Bx - Ax) + Ay;
					
				 }
				 else
				 {
					 if (quadrant(Ax, Ay) == 1)
					 {
						 newY = 2;
						 newX = (newY - Ay)*(Bx - Ax) / (By - Ay) + Ax;
					 }

					 if (quadrant(Ax, Ay) == 4)
					 {
						 newY = -2;
						 newX = (newY - Ay)*(Bx - Ax) / (By - Ay) + Ax;
					 }
					
				 }
				 x = distance(Ax, Ay, newX, newY);
				 s += function(x);				 
				
			 }

			 if (quadrant(Ax, Ay) == 2 || quadrant(Ax, Ay) == 3)
			 {
				 if (tangensL < tangens) 
				 {
					 newX = -5;
					 newY = (newX - Ax)*(By - Ay) / (Bx - Ax) + Ay;
				 }
				 else
				 {
					 if (quadrant(Ax, Ay) == 2)
					 {
						 newX = 2;
						 newY = (newY - Ay)*(Bx - Ax) / (By - Ay) + Ay;
					 }

					 if (quadrant(Ax, Ay) == 3)
					 {
						 newY = -2;
						 newX = (newY - Ay)*(Bx - Ax) / (By - Ay) + Ay;
					 }
				 }

				 
				 x = distance(Ax, Ay, newX, newY);
				 s += function(x);
			 }
			 
			
		 }




		 //B in rectangle
		 if (check(Ax, Ay) == 0 && check(Bx, By) == 1)
		 {
			 if (Ax == Bx)
			 {
				 if (quadrant(Bx, By) == 1 || quadrant(Bx, By) == 2)
				 {
					 x= distance(Ax, 2, Bx, By);
					 s += function(x);	
				 }
					 

				 if (quadrant(Bx, By) == 4 || quadrant(Bx, By) == 3)
				 {
					 x= distance(Ax, -2, Bx, By); 
					 s += function(x);
	
				 } 
			 }

			 if (Ay == By)
			 {
				 if (quadrant(Bx, By) == 1 || quadrant(Bx, By) == 4)
				 {
					 x= distance(5, Ay, Bx, By);
					 s += function(x);
				 }

				 if (quadrant(Bx, By) == 2 || quadrant(Bx, By) == 3)
				 {
					 x= distance(-5, Ay, Bx, By);
					 s += function(x);
					
				 }
					
			 }

			 tangensL = fabs(Ay) / fabs(Ax);
			
			 if (tangens == tangensL)
			 {
				 if (quadrant(Ax, Ay) == 1)
				 {
					 newX = 5;
					 newY = 2;
				 }

				 if (quadrant(Ax, Ay) == 2)
				 {
					 newX = -5;
					 newY = 2;
				 }

				 if (quadrant(Ax, Ay) == 3)
				 {
					 newX = -5;
					 newY = -2;
				 }

				 if (quadrant(Ax, Ay) == 4)
				 {
					 newX = 5;
					 newY = -2;
				 }
			 }
			
			 
			 if (quadrant(Bx, By) == 1 || quadrant(Bx, By) == 4 || quadrant(Bx, By) == 0)
			 {
				
				 if (tangensL < tangens) 
				 {
					 newX = 5;
					 newY = (newX - Bx)*(Ay - By) / (Ax - Bx) +By;
					 
				 }
				 else
				 {

					 if (quadrant(Ax, Ay) == 1)
					 {
						 newY = 2;
						 newX = (newY - By)*(Ax - Bx) / (Ay - By) + Bx;
					 }

					 if (quadrant(Ax, Ay) == 4)
					 {
						 newY = -2;
						 newX = (newY - By)*(Ax - Bx) / (Ay - By) + Bx;
					 }
				 }

				 x = distance(Bx, By, newX, newY);
				 s += function(x);
				 
			 }

			 if (quadrant(Bx, By) == 2 || quadrant(Bx, By) == 3)
			 {
				 if (tangensL < tangens) 
				 {
					 newX = -5;
					 newY = (newX - Bx)*(Ay - By) / (Ax - Bx) + By;
				 }
				 else
				 {
					 if (quadrant(Ax, Ay) == 2)
					 {
						
						 newY = 2;
						 newX = (newY - By)*(Ax - Bx) / (Ay - By) + Bx;
					 }

					 if (quadrant(Ax, Ay) == 3)
					 {
						
						 newY = -2;
						 newX = (newY - By)*(Ax - Bx) / (Ay - By) + Bx;
					 }
				 }
				
				 x = distance(Bx, By, newX, newY);
				 s += function(x);
				
			 }
			
		 }
		
	}
	
	cout << fixed<<setprecision(3)<<s << '\n';

	return 0;
}