#include <iostream>
#include<cmath>

using namespace std;
int main()
{
	/*double r;
	cin >> r;

	double const PI = 3.14;

	double Scircle, Sq;
	Sq = 4 * r*r;
	Scircle = PI*r*r;

	if (r <= 0) 
	{
		cout << "Invalid radius";
	}
	else
	{
		cout << "S=" << Sq - Scircle << endl;
	}*/
	double const PI = 3.14;
	
	double Ax, Ay;
	double Bx, By;
	double Cx, Cy;
	double Dx, Dy;
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;
	double r1, r2, r3, r4,S=0;
	r1 = fabs(Ax);
	r2 = Cx;
	r3 = fabs(By);
	r4 = Dy;

	double Scircle1, Sq1, Scircle2, Sq2, Scircle3, Sq3, Scircle4, Sq4;

	 

	Sq1 = 4 * r1*r1;
	Scircle1 = PI*r1*r1;
	S = (Sq1 - Scircle1) / 4;

	Sq2 = 4 * r2*r2;
	Scircle2 = PI*r2*r2;
	S = (Sq2 - Scircle2) / 4;

	Sq3 = 4 * r3*r3;
	Scircle3 = PI*r3*r3;
	S += (Sq3 - Scircle3) / 4;

	Sq4 = 4 * r4*r4;
	Scircle4 = PI*r4*r4;
	S += (Sq4 - Scircle4) / 4;

	 

	cout << "S="<<S<<endl;

	
	
	return 0;



}