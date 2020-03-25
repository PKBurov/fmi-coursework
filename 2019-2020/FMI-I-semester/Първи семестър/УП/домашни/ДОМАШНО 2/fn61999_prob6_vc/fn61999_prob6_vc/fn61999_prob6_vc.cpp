/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 6
* @compiler VC
*
*/

#include<iostream>
#include<cmath>
using namespace std;

unsigned int bynum(int n, int k)
{
	if (k == 0 || n == k)
		return 1;
	else
		return  bynum(n - 1, k - 1);
}

int main()
{
	int n;
	unsigned long long rezult;
	cin >> n;

	for (int k = 0; k <= n; k++)
	{
		rezult = bynum(n,k);
		cout << rezult;
		if (k != n) cout << " ";
	}

	cout << "\n";
	return 0;
}