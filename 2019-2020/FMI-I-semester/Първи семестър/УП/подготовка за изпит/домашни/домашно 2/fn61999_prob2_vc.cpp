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

#include<iostream>
#include<cmath>

using namespace std;

bool Simple(int number)
{
	int br = 0;
	for (int i = 1; i <= number; i++)
	{
		if (number%i == 0)
			br++;
	}

	if (br == 2)
		return true;
	else 
		return false;
}

int main()
{
	int  p, q, br = 0;
	unsigned int n;
	cin >> n;
	int numberOne = 0,numberTwo;

	if (n == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			while (br < n)
			{
				numberOne++;
				
				if (Simple(numberOne) == 1 )
				{
					
					numberTwo = numberOne + 2;
					if(Simple(numberTwo)==1)
					{
						cout <<numberOne << " " <<numberTwo<< "\n";
						br++;
					}
					
				}
			}
		}
	}


	return 0;
}