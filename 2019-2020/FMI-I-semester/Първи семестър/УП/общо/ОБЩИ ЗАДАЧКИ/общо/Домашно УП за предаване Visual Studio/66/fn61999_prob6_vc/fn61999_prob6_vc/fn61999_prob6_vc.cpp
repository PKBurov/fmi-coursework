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

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double Ax = 0, Ay = 0, Bx = 0, By = 0, Cx = 0, Cy = 0, Dx = 0, Dy = 0; //rectangle1
	double Ex = 0, Ey = 0, Fx = 0, Fy = 0, Gx = 0, Gy = 0, Hx = 0, Hy = 0; //rectangle2
	double heightRect1, heightRect2, weightRect1, weightRect2;

	double checkRight;
	double checkUp;

	double Surface = 0;

	cin >> Ax >> Ay;
	cin >> heightRect1 >> weightRect1;

	Cx = Ax + weightRect1;
	Cy = Ay + heightRect1;

	//cout << "C (" << Cx << ";" << Cy << ")" << endl;

	cin >> Ex >> Ey;
	cin >> heightRect2 >> weightRect2;

	Gx = Ex + weightRect1;
	Gy = Ey + heightRect1;

	//cout << "G (" << Gx << ";" << Gy << ")" << endl;


	Dx = Ax;
	Dy = Ay + heightRect1;

	Hx = Ex;
	Hy = Ey + heightRect2;

	//cout << "D (" << Dx << ";" << Dy << ")" << endl;
	//cout << "H (" << Hx << ";" << Hy << ")" << endl;


	// which is on the right side

	checkRight = fmax(Ax, Ex);
	if (checkRight == Ax) //cout << "Rectangle1:RIGHT Rectangle2:LEFT" << endl;
	if (checkRight == Ex) //cout << "Rectangle1:LEFT Rectangle2:RIGHT" << endl;


	// which is UP
	checkUp = fmax(Ay, Ey);
	if (checkUp == Ay) cout << "Rectangle1:Up Rectangle2:Down" << endl;
	if (checkUp == Ey) cout << "Rectangle1:Down Rectangle2:Up" << endl;

	double lenghtAD, lenghtEH, lenghtAH, lenghtFG, lenghtBC;
	lenghtAD = abs(Ay - Dy);
	lenghtEH = abs(Ey - Hy);
	lenghtAH = abs(Ay - Hy);
	lenghtFG = abs(Fy - Gy);
	lenghtBC = abs(By - Cy);

	double lenghtAB, lenghtEF, lenghtAF;
	lenghtAB = abs(Ax - Bx);
	lenghtEF = abs(Ex - Fx);
	lenghtAF = abs(Ax - Fx);

	double lenghtAG, lenghtBG;
	lenghtAG = abs(Ax - Gx);
	lenghtBG = abs(By - Gy);


	if (Ax<Ex && Bx<Ex)
	{
		cout << Surface << '1\n';
		return 0;
	}

	if (Ex<Ax && Fx<Ax)
	{
		cout << Surface << '2\n';
		return 0;
	}

	if (Ay<Ey && Dy<Ey)
	{
		cout << Surface << '3\n';
		return 0;
	}

	if (Ey<Ay && Hy<Ay)
	{
		cout << Surface << '4\n';
		return 0;
	}

	if (Ex == Cx || Ax == Gx)
	{
		cout << Surface << "5\n";
		return 0;
	}

	double lenghtEB, lenghtBH, lenghtED, lenghtFC, lenghtDC,lenghtHG;
	lenghtEB= abs(Ex - Bx);
	lenghtBH = abs(By - Hy);
	lenghtED= abs(Ey - Dy);
	lenghtFC= abs(Fy - Cy);
	lenghtDC=abs(Dx - Cx);
	lenghtHG= abs(Hx - Gx);

	if (checkUp == Ay) // "Rectangle1:Up Rectangle2:Down" 
	{
		if (lenghtAB + lenghtEF >= lenghtAF)
		{
			Surface = lenghtAB*lenghtAH;
			cout << Surface << '6\n';
			return 0;
		}

		if (checkRight == Ax)//"Rectangle1:RIGHT Rectangle2:LEFT"
		{
			Surface = lenghtAG*lenghtBG;
			cout << Surface << '7\n';
			return 0;
		}

		if (checkRight == Ex) //"Rectangle1:LEFT Rectangle2:RIGHT"
		{
			Surface = lenghtEB*lenghtBH;
			cout << Surface << '8\n';
			return 0;
		}

	}

	if (checkUp == Ey) //"Rectangle1:Down Rectangle2:Up" 
	{
		if (lenghtAB + lenghtEF >= lenghtAF)
		{
			Surface = lenghtEF*lenghtED;
			cout << Surface << '9\n';
			return 0;
		}

		if (checkRight == Ax)//"Rectangle1:RIGHT Rectangle2:LEFT"
		{
			Surface = lenghtAF*lenghtFC;
			cout << Surface << '10\n';
			return 0;
		}

		if (checkRight == Ex) //"Rectangle1:LEFT Rectangle2:RIGHT"
		{
			Surface = lenghtEB*lenghtFC;
			cout << Surface << '11\n';
			return 0;
		}

	}


	//1 in 1
	double SurfaceRectangle1, SurfaceRectangle2;
	SurfaceRectangle1 = lenghtAB*lenghtAD;
	SurfaceRectangle2 = lenghtEF*lenghtEH;

	if (lenghtAB > lenghtEF && lenghtBC > lenghtFG && lenghtDC > lenghtHG && lenghtAD > lenghtEH)
	{
		SurfaceRectangle2 = lenghtEF*lenghtEH;
	}

	if (lenghtAB < lenghtEF && lenghtBC < lenghtFG && lenghtDC < lenghtHG && lenghtAD < lenghtEH)
	{
		SurfaceRectangle1 = lenghtAB*lenghtAD;
	}

	if(Dy==Fy)
	{
		cout << Surface << '12\n';
		return 0;
	}

	if (By == Hy)
	{
		cout << Surface << '13\n';
		return 0;
	}

	return 0;
}