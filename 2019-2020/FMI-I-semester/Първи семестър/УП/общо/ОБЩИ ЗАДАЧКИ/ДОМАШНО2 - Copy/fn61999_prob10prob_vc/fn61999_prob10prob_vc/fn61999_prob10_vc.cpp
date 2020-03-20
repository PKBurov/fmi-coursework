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
#include<cmath>
using namespace std;



int main()
{
	int p1, p2, n;
	int nq;
	int Vp1 = 0, Vp2;
	int maxVp1 = 0, maxVp2 = 0;
	int numberP1, numberP2;
	int rezultP1, rezultP2;


	cin >> nq;
	for (int i = 0; i < nq; i++)
	{
		cin >> p1 >> n >> p2;
		if (n == 0)
		{
			cout << "infinity\n";
		}
		else
		{

			int Vp1 = 1, Vp2 = 1;
			int j = 0, k = 0;

			numberP1 = pow(p1, j);
			numberP2 = pow(p2, k);

			while (numberP1 <= n)
			{
				if (n%numberP1 == 0)
				{
					Vp1 = j;
					if (maxVp1<Vp1)
						maxVp1 = Vp1;

				}
				numberP1 = numberP1*p1;

				j++;
			}
			rezultP1 = maxVp1;
			maxVp1 = 0;

			while (numberP2 <= n)
			{
				if (n%numberP2 == 0)
				{
					Vp2 = k;
					if (maxVp2<Vp2)
						maxVp2 = Vp2;
				}
				numberP2 = numberP2*p2;
				k++;
			}
			rezultP2 = maxVp2;
			maxVp2 = 0;
			cout << fmax(rezultP1, rezultP2) << '\n';

		}
	}

	return 0;
}