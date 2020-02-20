#include<iostream>
using namespace std;
/*
Задача 1. 
а) Да се напише програма, която извежда интервал от време, зададен като брой секунди (не повече от 107), в брой дни, часове, минути и секунди.
Пример: 100000 секунди = 1 ден, 3 часа, 46 минути и 40 секунди.

*/

int main()
{
	/*
	int sec=0, min = 0, h = 0, d = 0 ;
	int seconds=0, minutes=0, hours=0, days=0;
	cin >> sec;
	
	if (sec < 60)
	{
		seconds = sec;
	}
	else
	{
		seconds = sec % 60;
		minutes = sec / 60;
		if (minutes > 60)
		{
			min = minutes;
			minutes = min % 60;
			hours = min / 60;

			if (hours > 24)
			{
				h = hours;
				hours = h % 24;
				days = h / 24;
			}
		}
	}


	cout<<sec<<" seconds = " << days << " days, "<<hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl;
	б) Да се напише програма, която намира сумата на квадратните корени на всички положителни нечетни числа в даден затворен интервал [a; b],
	*/
	int a, b;
	cin >> a >> b;
	int arr[100];
	int index = 0;
	for (int i = a ; i <= b; i++)
	{
		if (i > 0)
		{
			arr[index] = i;
			index++;
		}
	
	}
	int sum = 0;
	for (int i = 0; i <index; i++)
	{
		int p = arr[i] * arr[i];
		if (p % 2 != 0)
			sum += p;
	}
	cout << sum << endl;
	return 0;
}