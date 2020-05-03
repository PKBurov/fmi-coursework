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

#include<iostream>
#include<cmath>
#include <iomanip>  

using namespace std;
int main()
{

	int n, t, v;
	double d;
	double vN, arr, sN, v0 = 0;

	double s = 0;
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		cin >> arr;
		vN = v0 + arr*d;
		if (vN < 0)
			vN = 0;
		sN = v0*d + 0.5*arr*d*d;
		if (sN > 0)
			s += sN;
		v0 = vN;
	}

	cout <<fixed <<setprecision(5) << s << '\n';
	return 0;
}