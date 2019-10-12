/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 7
* @compiler VC
*
*/


#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	double x, y;

	cin >> x >> y;

	if (x == 0 && y == 0)		cout << "Neutral\n";

	if (pow(x, 2) + pow(y, 2) >= 36)	 cout << "Neutral\n";

	if (pow(x, 2) + pow(y - 3, 2) == 1)		 cout << "Neutral\n"; //small black

	if (pow(x, 2) + pow(y + 3, 2) == 1)  cout << "Neutral\n"; //small white

	if ((pow(x, 2) + pow(y - 3, 2) == 9) && x>0 && y>0)		 cout << "Neutral\n"; //gig white

	if ((pow(x, 2) + pow(y + 3, 2) == 9) && x<0 && y<0)  cout << "Neutral\n"; //big black



	if (pow(x, 2) + pow(y + 3, 2) < 1)  cout << "Good\n"; //small white
	if (pow(x, 2) + pow(y - 3, 2) < 1)		 cout << "Good\n"; //small black

	if ((pow(x, 2) + pow(y - 3, 2) > 1) && (pow(x, 2) + pow(y - 3, 2) < 9))
	{
		cout << "Good\n"; //upper circle
		return 0;
	}

	if ((pow(x, 2) + pow(y + 3, 2) > 1) && (pow(x, 2) + pow(y + 3, 2) < 9))
	{
		cout << "Evil\n"; //down circle
		return 0;
	}

	//right part
	if ((pow(x, 2) + pow(y - 3, 2) > 9) && x>0 && x<6 && (pow(x, 2) + pow(y, 2) < 36)) cout << "Evil\n";
	//left part
	if ((pow(x, 2) + pow(y + 3, 2) > 9) && x<0 && x>(-6) && (pow(x, 2) + pow(y, 2) < 36)) cout << "Good\n";


	return 0;
}