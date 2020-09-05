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
* @compiler VC
*
*/

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	double Ax, Ay, x, y, r0, r1, realAx, realAy, weight, height;
	cin >> Ax >> Ay;
	cin >> x >> y;

	realAx = Ax + x;
	realAy = Ay + y;


	if (x == 0 && y == 0)
	{
		r0 = pow(Ax, 2) + pow(Ay, 2);

		if (r0 >= 0 && r0 <= 1) cout << 60 << '\n';
		if (r0>1 && r0<9) cout << 20 << '\n';
		if (r0 == 9) cout << 0 << '\n';
		if (r0 == 64) cout << 0 << '\n';
		if (r0>9 && r0 < 64) cout << 10 << '\n';
		if (r0>64) cout << 0 << '\n';

	}
	else
	{
		r1 = pow(realAx, 2) + pow(realAx, 2);

		if (r1 >= 0 && r1 <= 1) cout << 60 << '\n';
		if (r1>1 && r1<9) cout << 20 << '\n';
		if (r1 == 9) cout << 0 << '\n';
		if (r1 == 64) cout << 0 << '\n';
		if (r1>9 && r1 < 64) cout << 10 << '\n';
		if (r1>64) cout << 0 << '\n';
	}


	return 0;
}
