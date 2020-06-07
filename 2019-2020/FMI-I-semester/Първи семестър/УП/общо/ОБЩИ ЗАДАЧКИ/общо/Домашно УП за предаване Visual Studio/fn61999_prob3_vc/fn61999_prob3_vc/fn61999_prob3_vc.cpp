// fn61999_prob3_vc.cpp : Defines the entry point for the console application.
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
* @task 3
* @compiler GCC
*
*/


#include "stdafx.h"
#include <iostream>


using namespace std;

int main()

{

	unsigned int number;
	int similarity;
	cin >> number;
	
	int ostSteps1, ostSteps2, ostSteps3, ostSteps4, ostSteps5, ostSteps6, ostSteps7, ostSteps8;
	int numberSteps1, numberSteps2, numberSteps3, numberSteps4, numberSteps5, numberSteps6, numberSteps7, numberSteps8 ;
	
	numberSteps1 = number / 16;
	ostSteps1 = number % 16;
	number = numberSteps1;
	similarity = ostSteps1;
	if (ostSteps1 == 0)
	{
		cout << "Yes" << '\n';
		return 0;
	}
	else
	{
		numberSteps2 = number / 16;
		ostSteps2 = number % 16;
		number = numberSteps2;
		if(ostSteps1 == ostSteps2)
			numberSteps3 = number / 16;
		else
		{
			cout << "No" << '\n';
			return 0;
		}
	}


	if (numberSteps2 == 0 && ostSteps2 == similarity)
	{
		cout << "Yes" << '\n';
		return 0;
	}
	else
	{
		ostSteps3 = number % 16;
		number = numberSteps3;
		if (ostSteps2 == ostSteps3)
			numberSteps4 = number / 16;
		else
		{
			cout << "No" << '\n';
			return 0;
		}
	}
	

	ostSteps4 = number % 16;
	number = numberSteps4;
	if (numberSteps3 == 0 && ostSteps3 == similarity)
	{
		cout << "Yes" << '\n';
		return 0;
	}
	else
	{
		if (ostSteps3 == ostSteps4)
			numberSteps5 = number / 16;
		else
		{
			cout << "No" << '\n';
			return 0;
		}
	}
	

	ostSteps5 = number % 16;
	number = numberSteps5;
	if (numberSteps4 == 0 && ostSteps4 == similarity)
	{
		cout << "Yes" << '\n';
		return 0;
	}
	else
	{
		if (ostSteps4 == ostSteps5)
			numberSteps6 = number / 16;
		else
		{
			cout << "No" << '\n';
			return 0;
		}
	}

	

	ostSteps6 = number % 16;
	number = numberSteps6;
	if (numberSteps5 == 0 && ostSteps5 == similarity)
	{
		cout << "Yes" << '\n';
		return 0;
	}
	else
	{
		if (ostSteps5 == ostSteps6)
			numberSteps7 = number / 16;
		else
		{
			cout << "No" << '\n';
			return 0;
		}
	}
	

	ostSteps7 = number % 16;
	number = numberSteps7;
	if (numberSteps6 == 0 && ostSteps6 == similarity)
	{
		cout << "Yes" << '\n';
		return 0;
	}
	else
	{
		if (ostSteps6 == ostSteps7)
			numberSteps8 = number / 16;
		else
		{
			cout << "No" << '\n';
			return 0;
		}
	}
	

	ostSteps8 = number % 16;
	number = numberSteps8;
	if (numberSteps7 == 0 && ostSteps7 == similarity)
	{
		cout << "Yes" << '\n';
		return 0;
	}
	else
	{
		if (ostSteps7 == ostSteps8)
			numberSteps8 = number / 16;
		else
		{
			cout << "No" << '\n';
			return 0;
		}
	}

	if (numberSteps8 == 0 && ostSteps8 == similarity)
	{
		cout << "Yes" << '\n';
		return 0;
	}
	else
	{
			cout << "No" << '\n';
			return 0;
	}
	



    
}

