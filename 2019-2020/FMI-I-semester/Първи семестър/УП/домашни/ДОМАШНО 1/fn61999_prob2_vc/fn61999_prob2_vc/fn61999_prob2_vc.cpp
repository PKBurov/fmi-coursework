

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
#include<cmath>

using namespace std;

int main()
{
	long long egn;
	int year;
	cin >> egn;
	//take month
	int month, month1, month2;
	month1 = egn / pow(10, 7);
	month1 = month1 % 10;


	month2 = egn / pow(10, 6);
	month2 = month2 % 10;

	month = month1 * 10 + month2;

	//control number
	int a, b, c, d, e, f, z, t, k, m;
	a = egn / pow(10, 9);

	b = egn / pow(10, 8);
	b %= 10;

	c = egn / pow(10, 7);
	c %= 10;

	d = egn / pow(10, 6);
	d %= 10;

	e = egn / pow(10, 5);
	e %= 10;

	f = egn / pow(10, 4);
	f %= 10;

	z = egn / pow(10, 3);
	z %= 10;

	t = egn / pow(10, 2);
	t %= 10;

	k = egn / 10;
	k %= 10;

	m = egn % 10;

	if (egn > 999999999 && egn<1000000000)
	{
		cout << "Bad input data!\n";
		return 0;
	}
	else
	{
		year = egn / pow(10, 8);
		

		int day, day1, day2;
		day1 = egn / pow(10, 5);
		day1 = day1 % 10;


		day2 = egn / pow(10, 4);
		day2 = day2 % 10;

		day = day1 * 10 + day2;


		if (day > 31 || day < 1)
		{
			cout << "Bad input data!\n";
			return 0;
		}


		if (month >= 1 && month <= 12)
			year = 1900 + year;
		else
			if (month >= 21 && month <= 32)
			{
				month = month - 20;
				year = 1800 + year;
			}
			else
				if (month >= 41 && month <= 52)
				{
					month = month - 40;
					year = 2000 + year;
				}
				else
				{
					cout << "Bad input data!\n";
					return 0;
				}

		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day>30)
			{
				cout << "Bad input data!\n";
				return 0;
			}
		}

		if (month == 2)
		{
			if (day>29)
			{
				cout << "Bad input data!\n";
				return 0;
			}
		}

		if (month == 2)
		{
			if ((year % 4 == 0) && (year % 100 != 0))
			{
				if (day >= 30)
				{
					cout << "Bad input data!\n";
					return 0;
				}
			}
			else
			{
				if (day >= 29)
				{
					cout << "Bad input data!\n";
					return 0;
				}
			}
		}

		
		long long sum = a * 2 + b * 4 + c * 8 + d * 5 + e * 10 + f * 9 + z * 7 + t * 3 + k * 6;
		
		sum = sum % 11;
		

		if (sum<10 && sum != 0 && sum != m)
		{
			cout << "Bad input data!\n";
			return 0;
		}
		if (sum>10 && m != 0)
		{
			cout << "Bad input data!\n";
			return 0;
		}


		int sex = egn / 10;
		sex %= 10;

		if (day<10)
		{
			cout << "0";
		}

		cout << day << ".";
		if (month<10)
		{
			cout << "0";
		}

		cout << month << ".";
		cout << year << " ";
		if (sex % 2 == 0)
			cout << "M\n";
		else
			cout << "F\n";


	}


}