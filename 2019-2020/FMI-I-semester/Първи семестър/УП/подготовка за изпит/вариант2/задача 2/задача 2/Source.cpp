#include<iostream>
using namespace std;
/*
Задача 2. а) Да се напише функция, която проверява дали дадено цяло число x съдържа в записа си десетичната цифра n не повече от два пъти.
б) Да се напише функция, която по дадени цяло число k(1 ≤ k ≤ 100), десетична цифра n и масив от цели числа a, определя дали в a има поне k числа, 
които съдържат цифрата n в записа си не повече от два пъти.
*/

int count(int number)
{
	int counter = 1;
	while (number > 0)
	{
		number = number / 10;
		if(number!=0)
		counter++;
	}

	return counter;
}

bool check(int x, int n)
{
	int counterNumber = count(x);
	int counterN = count(n);
	int divisor = pow(10,2);
	bool flag = false;
	int temp = 0, counter = 0;

	if (counterNumber == 1 && counterN==1 && counterNumber!= counterN)
	{
		flag = false;
	}
	else
	{
		while (x > 0)
		{
			temp = x % divisor;
			if (temp == n)
				counter++;
			x = x / 10;
		}

		if (counter >= 2)
			flag = true;
		else flag = false;
	}

	return flag;
}

int main()
{
	int n, x;
	cin >> x >> n;
	
	cout << check(x, n) << endl;
	
	return 0;
}