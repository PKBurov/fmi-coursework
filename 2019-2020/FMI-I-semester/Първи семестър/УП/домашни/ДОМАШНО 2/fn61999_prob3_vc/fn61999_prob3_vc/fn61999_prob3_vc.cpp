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
* @compiler VC
*
*/

#include<iostream>
#include<cmath>
using namespace std;

int count(int number)
{
	int br = 0;
	while (number != 0)
	{
		number = number / 10;
		br++;
	}
	return br;
}
int main()
{
	unsigned long long a, b;
	cin >> a >> b;
	int m,  check;
	int br = 0;
	m = count(a);

	int degree = pow(10, m);

	while (b != 0)
	{
		check = b % degree;

		if (check == a)
			br++;
		b = b / 10;
	}
	
	
	cout << br << "\n";

	return 0;
}