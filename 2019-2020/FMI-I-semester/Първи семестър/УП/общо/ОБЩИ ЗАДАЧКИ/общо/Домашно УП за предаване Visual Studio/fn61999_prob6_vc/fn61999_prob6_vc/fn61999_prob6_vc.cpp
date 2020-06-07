// fn61999_prob6_vc.cpp : Defines the entry point for the console application.
//



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
* @compiler GCC
*
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double Ax=0, Ay = 0, Bx = 0, By = 0, Cx = 0, Cy = 0, Dx = 0, Dy = 0; //rectangle1
	double Ex = 0, Ey = 0, Fx = 0, Fy = 0, Gx = 0, Gy = 0, Hx = 0, Hy = 0; //rectangle2
	double heightRect1, heightRect2, weightRect1, weightRect2;

	double checkRight;
	double checkUp;

	double Surface = 0;
	
	cin >> Ax >> Ay;
	cin >> heightRect1 >> weightRect1;
	
	Cx = Ax + weightRect1;
	Cy = Ay + heightRect1;

	cout << "C (" << Cx << ";" << Cy <<")" <<endl;

	cin >> Ex >> Ey;
	cin >> heightRect2 >> weightRect2;

	Gx = Ex + weightRect1;
	Gy = Ey + heightRect1;

	cout << "G (" << Gx << ";" << Gy << ")" << endl;

	// which is on the right side

	checkRight = fmax(Ax, Ex);
	if (checkRight == Ax) cout << "Rectangle1:RIGHT Rectangle2:LEFT" << endl;
	if (checkRight == Ex) cout << "Rectangle1:LEFT Rectangle2:RIGHT"<<endl;


	// which is UP
	checkUp = fmax(Ay, Ey);
	if (checkUp == Ay) cout << "Rectangle1:Up Rectangle2:Down" << endl;
	if (checkUp == Ey) cout << "Rectangle1:Down Rectangle2:Up" << endl;

	double lenghtAD, lenghtEH, lenghtAH, lenghtFG, lenghtBC;
	lenghtAD = abs(Ax - Dx);
	lenghtEH = abs(Ex - Hx);
	lenghtAH = abs(Ax - Hx);
	lenghtFG = abs(Fx - Gx);
	lenghtBC = abs(Bx - Cx);
	
	double lenghtAB, lenghtEF, lenghtAF;
	lenghtAB = abs(Ax - Bx);
	lenghtEF= abs(Ex - Fx);
	lenghtAF = abs(Ax - Fx);


	if ((lenghtAB + lenghtEF >= lenghtAF) && Bx < Ex)
	{
	cout << Surface << '\n';
	return 0;
	}
	else
	{
		if (checkUp == Ay) // "Rectangle1:Up Rectangle2:Down" 
		{
			Surface = lenghtEF*lenghtFG;
			cout << lenghtEF << "\n";
			cout << lenghtFG << "\n";
			cout << Surface << "\n";
			return 0;
		}
			
		if (checkUp == Ey) //"Rectangle1:Down Rectangle2:Up" 
		{
			Surface = lenghtEF*lenghtAH;
			cout << lenghtEF << "\n";
			cout << lenghtAH << "\n";
			cout << Surface << "\n";
			return 0;
		}
	}

	if ((lenghtAD + lenghtEH >= lenghtAF) && Dy < Ey)
	{
		cout << Surface << '\n';
		return 0;
	}

	Dx = Ax;
	Dy = Ay + heightRect1;

	Hx = Ex;
	Hy = Ey + heightRect2;

	cout << "D (" << Dx << ";" << Dy << ")" << endl;
	cout << "H (" << Hx << ";" << Hy << ")" << endl;

	

	if (lenghtAD + lenghtEH >= lenghtAH)
	{
		cout << Surface << "\n";
		return 0;
	}

	if(Ex==Cx || Ax==Gx) 
	{
		cout << Surface << "1111\n";
		return 0;
	}


	lenghtAF = abs(Ax - Fx);
	if (checkRight == Ex) //Rectangle1:LEFT Rectangle2:RIGHT"
	{
		if( (abs(lenghtAB - lenghtEF) > 0) && (abs(lenghtBC - lenghtEH) > 0))
		{
			Surface = abs(Ex - Cx)*abs(Ey - Cy);
			return 0;
		}

	}

	if (checkRight == Ax) //"Rectangle1:RIGHT Rectangle2:LEFT"
	{
		if ((abs(lenghtAB - lenghtEF) > 0) && (abs(lenghtAD - lenghtFG) > 0))
		{
			Surface = abs(Ax - Gx)*abs(Ay - Gy);
			return 0;
		}

	}
	//1 in 1
	double SurfaceRectangle1, SurfaceRectangle2;
	SurfaceRectangle1 = lenghtAB*lenghtAD;
	SurfaceRectangle2 = lenghtEF*lenghtEH;

	if (SurfaceRectangle1 < SurfaceRectangle2 && lenghtAB < lenghtEH && lenghtAD < lenghtEH)
		cout << SurfaceRectangle1 << '\n';

	cout<< abs(Ex - Cx)*abs(Ey - Cy);
	cout << abs(Ax - Gx)*abs(Ay - Gy);
	cout << abs(Ax - Dx);
	cout << abs(Ex - Hx);
	cout << abs(Ax - Hx);
	cout << abs(Fx - Gx);
	cout << abs(Bx - Cx);


	return 0;
}