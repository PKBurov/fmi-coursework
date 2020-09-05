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

using namespace std;
#include <iostream>

void minPrize(unsigned int prize[], unsigned int minutes[], unsigned int mb[], unsigned int sms[], unsigned int position[], int n, bool flag)
{
	int minElement;
	int change;

	for (int i = 0; i < n - 1; i++)
	{
		minElement = i;

		for (int j = i + 1; j < n; j++)
		{

			if (prize[j] < prize[minElement])
			{
				if (!flag)
				{
					minElement = j;
				}

				if (flag && position[j] == position[minElement])
				{
					minElement = j;
				}
			}

		}

		if (minElement != i)
		{
			swap(prize[i], prize[minElement]);
			swap(minutes[i], minutes[minElement]);
			swap(mb[i], mb[minElement]);
			swap(sms[i], sms[minElement]);
			swap(position[i], position[minElement]);
		}
	}
}

int main()
{
	unsigned int n;
	cin >> n;
	unsigned int prize[10000];
	unsigned int minutes[10000];
	unsigned int mb[10000];
	unsigned int sms[10000];
	unsigned int position[10000];


	for (int i = 0; i < n; i++)
	{
		cin >> prize[i];
		cin >> minutes[i];
		cin >> mb[i];
		cin >> sms[i];
		position[i] = i;
	}

	unsigned int minRezult;
	unsigned int mbRezult;
	unsigned int smsRezult;

	cin >> minRezult >> mbRezult >> smsRezult;
	minPrize(prize, minutes, mb, sms, position, n, false);
	minPrize(position, minutes, mb, sms, prize, n, true);

	unsigned int counter = 0;
	for (int t = 0; t < n; t++)
	{
		if (minRezult <= minutes[t] &&
			mbRezult <= mb[t] &&
			smsRezult <= sms[t])
		{
			cout << prize[t] << " " << minutes[t] << " " << mb[t] << " " << sms[t] <<'\n';
			counter++;
		}
	}

	if (counter == 0)
	{
		cout << "No solution"<< '\n';
	}
	return 0;
}

