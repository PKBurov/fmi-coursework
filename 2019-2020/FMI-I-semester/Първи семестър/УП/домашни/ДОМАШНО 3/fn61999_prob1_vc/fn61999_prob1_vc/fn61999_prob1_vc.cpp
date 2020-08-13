/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 9
* @compiler VC
*
*/

#include<iostream>
using namespace std;

void row(unsigned  long long n)
{
	if (n == 1)
	{
		cout << 1;
		return;
	}
	else
	{
		row(n - 1);
		cout << n;
		row(n - 1);
	}
}
int main()
{
	unsigned long long n;
	cin >> n;
	row(n);
	cout << '\n';
	return 0;
}