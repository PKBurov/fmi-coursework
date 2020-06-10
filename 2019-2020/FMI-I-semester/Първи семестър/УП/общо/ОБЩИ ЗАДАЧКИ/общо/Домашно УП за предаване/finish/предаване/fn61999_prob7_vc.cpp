// fn61999_prob7_vc.cpp : Defines the entry point for the console application.
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
* @task 7
* @compiler GCC
*
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	double x, y;

	cin >> x >> y;

	if (x==0 && y==0)		cout << "Neutral\n";

	if (pow(x, 2) + pow(y, 2) >= 36)	 cout << "Neutral\n";

	if(pow(x, 2) + pow(y-3, 2)==1)		 cout << "Neutral\n"; //malko cherno

	if (pow(x, 2) + pow(y + 3, 2) == 1)  cout << "Neutral\n"; //malko bqlo

	if ((pow(x, 2) + pow(y - 3, 2) == 9) && x>0 && y>0)		 cout << "Neutral\n"; //golqmo bqlo

	if ((pow(x, 2) + pow(y + 3, 2) == 9) && x<0 && y<0)  cout << "Neutral\n"; //golqmo cherno



	if (pow(x, 2) + pow(y + 3, 2) < 1)  cout << "Good\n"; //malko bqlo
	if (pow(x, 2) + pow(y - 3, 2) < 1)		 cout << "Good\n"; //malko cherno

	if ((pow(x, 2) + pow(y - 3, 2) > 1) && (pow(x, 2) + pow(y - 3, 2) < 9))
	{
		cout << "Good\n"; //gorno krukche
		return 0;
	}
	
	if ((pow(x, 2) + pow(y + 3, 2) > 1) && (pow(x, 2) + pow(y + 3, 2) < 9))
	{
		cout << "Evil\n"; //dolno krukche
		return 0;
	}

	//dqsna chast
	if((pow(x, 2) + pow(y - 3, 2) > 9) && x>0 && x<6 && (pow(x, 2) + pow(y, 2) < 36)) cout << "Evil\n";
	//lqva chast
	if ((pow(x, 2) + pow(y + 3, 2) > 9) && x<0 && x>(-6) && (pow(x, 2) + pow(y, 2) < 36)) cout << "Good\n";
	



	/*dqsna chast
		if ((pow(x, 2) + pow(y - 3, 2) > 9) && x > 0 && x<6)  cout << "Evil3\n";
		

		if ((pow(x, 2) + pow(y + 3, 2) > 1) && x > 0 && x<6 )  cout << "Evil2\n";
		
	

	lqva chast
		if ((pow(x, 2) + pow(y - 3, 2) > 1) && x < 0 && x>(-6))	  cout << "Good3\n";
		

		if ((pow(x, 2) + pow(y + 3, 2) > 9) && x < 0 && x>(-6))  cout << "Good2\n";
		
	

	if ((pow(x, 2) + pow(y - 3, 2) < 9) && (pow(x, 2) + pow(y - 3, 2) > 1))		 cout << "Good1\n";

	if ((pow(x, 2) + pow(y + 3, 2) < 9) && (pow(x, 2) + pow(y + 3, 2) > 1))  cout << "Evil1\n"; 
	
	*/

    return 0;
}

