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

#include<iostream>
#include<cmath>

using namespace std;

int modul(int x, int n, int m)
{
	int mod = x%m;
	int p = 1;

	for (int i = 0; i < n; i++)
	{
		p = p*mod;
		p = p%m;
	}

	return p;
}



int main()
{
	unsigned int n, m, y, x, br = 0,check=0;
	int interval = 0;

	cin >> n >> m >> y;

	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			x = i;
			
			if(modul(x, n, m)==y)
			{
				if (interval == 1)
					cout << " ";
				cout << x;
				interval = 1;
				check = 1;
				
			}
			else
				br++;

			i++;

		}

	}
	if (check == 0)
		cout << -1;
	
	cout << "\n";

	
	return 0;
}