/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 2
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int makeInParts[32];

void makeInPartsNumber(int number, int step, int pos,int result)
{

	if (number == result)
	{
		cout << result << " = "<<result<<'\n';
	}
	
	if (number == 0)
	{
		pos--;
		cout << result<<" = ";
		for (int i = 0; i < pos; i++)
		{
			cout << makeInParts[i] << " + ";
		}

		cout << makeInParts[pos] << endl;
	}

	for (int i = step; i>0; i--)
	{
		if (number >= i)
		{
			makeInParts[pos] = i;
			makeInPartsNumber(number - i, i, pos + 1,result);
		}
	}
}

int main()
{
	int number;
	cin >> number;
	
	if (number == 0 || number == 1)
	{
		cout << number << " = " << number << '\n';
	}
	if (number > 1)
	{
		makeInPartsNumber(number, number - 1, 0,number);
	}
		
	return 0;
	
}
