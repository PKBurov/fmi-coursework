// koreni na kv.uravnenie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	double a, b, c, d;
	cin >> a >> b >> c;
	d = b*b - 4 * a*c;
	cout << d << endl;

	
		if (d < 0)
		{
			cout << "nqma realni koreni"  << endl;
		}
		else
		{
			cout << "korenite na yravnenieto sa "<< (-b +sqrt(d))/ 2 * a << " sushto i " << (-b - sqrt(d)) / 2 * a  << endl;
		}
	
	
    return 0;
}

