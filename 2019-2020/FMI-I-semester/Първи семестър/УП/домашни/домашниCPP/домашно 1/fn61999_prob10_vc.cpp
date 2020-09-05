/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 10
* @compiler VC
*
*/

#include<iostream>


using namespace std;


int main()
{
	double a, b, c, d, e, f, x = 0, y = 0;

	cin >> a>>b>>e;
    cin >> c>>d>>f;
	

	if ((a*d - b*c) == 0)
	{
		if ((f*a - e*c) == 0)
		{
			cout << "Many solutions" << '\n';
			return 0;
		}
		else
		{
			cout << "No solution" << '\n';
			return 0;
		}
	}
	else
	{
		y = (f*a - e*c) / (a*d - b*c);

		if (a != 0)
		{
			x = (e - b*y) / a;
			cout << x << " " << y << "\n";
		}
		else
		{
			if (b == 0)
			{
				if (e == 0)
					cout << "Many solutions" << '\n';
				else
					cout << "No solution" << '\n';
			}
			else
				y = e / b;

			cout << x << " " << y << "\n";
		}


	}

	return 0;
}

