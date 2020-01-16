#include<iostream>
using namespace std;
/*
Да се намери сумата на цифрите на дадено естествено число n
Да се провери дали в десетичния запис на числото n съдържа цифрата 5
*/
int main()
{
	int number;
	cin >> number;
	int temp = 0;
	int counter = 0;
	int sum = 0;
	bool isContain = false;
	while (number)
	{
		counter++;

		temp = number % 10;
		if (temp == 5)
		{
			isContain = true;
		}
		sum += temp;
		number = number / 10;
	}
	cout << sum << '\n';
	cout << isContain << '\n';
	return 0;
}