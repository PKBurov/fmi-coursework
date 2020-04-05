#include<iostream>
#include<cmath>
using namespace std;
/*
Задача 1.
Да се напише програма, която извежда колко монети от 1 лв., 20 ст., 5 ст. и 1 ст. са нужни за изплащане на дадена сума до 100 лв., 
зададена като дробно число лева, с до две цифри след десетичната запетая. Да се избират възможно най-едри монети.
Пример: 2,77 лв. = 2 x 1 лв. + 3 x 20 ст. + 3 x 5 ст. + 2 x 1 ст.

*/

int main()
{
	/*double sum;
	cin >> sum;

	double temp =sum - (int)sum;
	int lv = (int)sum;
	int m20=0,m5=0,m1 =0;
	int monets = temp * 100;
	

	if (monets <= 20)
	{
		m20 = monets;
	}
	else
	{
		m20 = monets / 20;
		m5= monets % 20;
		if (monets <= 5)
		{
			m5 = m5;
		}
		else
		{
			int temp = m5;
			m5 = m5/5;
			m1 = temp % 5;
		}
	}

	cout << lv << " x 1 lv + " << m20 << " x 20 st + " << m5 << " x 5 st + " << m1 << " x 1 st"<< endl;
	б) Да се напише програма, която намира сумата на абсолютните стойности на кубовете на всички четни числа в даден затворен интервал [a; b],
	*/
	int a, b;
	cin >> a >> b;
	int arr[100];
	int index = 0;
	for (int i = a; i <= b; i++)
	{
		
			arr[index] = fabs(i);
			index++;

	}
	int sum = 0;
	for (int i = 0; i <index; i++)
	{
		
		int p = arr[i] * arr[i]* arr[i];
		//cout << p << " ";
		if (p % 2 == 0)
			sum += p;
	}
	cout << sum << endl;
	return 0;
}