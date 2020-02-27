#include <iostream>

int prime_func_interval(int num1, int num2)
{
	int sum_prime = 0;
	for (int i = num1; i < num2; i++)
	{
		if (i == 1) { continue; }
		int flag = 0;
		for (int j = 2; j <= num1/2 ; j++)
		{
			if (num1 % j ==0)
			{
				flag = 1;
				break;
			}
		}
		if (flag==0)
		{
			std::cout << num1 << std::endl;
			sum_prime = sum_prime + num1;
		}
		++num1;
	}
	return sum_prime;
}
void prime_and_sum(int num1, int num2) 
{
	int result = prime_func_interval(num1, num2);
	std::cout << result << std::endl;
}
int main()
{	
	prime_and_sum(2,100);
	std::cin.get();

}
	//calculator;

	//int num1=0, num2=0, choise, result;
	//cout << "Choose the 2 numers you want to calculate:" << endl;
	//cout << "a="; cin >> num1;
	//cout << "b="; cin >> num2;
	//cout << "Choose +,-,*,/ {1,2,3,4} ";
	//cin >> choise;

	//switch (choise)
	//{
	//case 1:
	//	result = num1 + num2;
	//	cout << "your number is = " << result << endl;
	//	break;
	//case 2:
	//	if (num1 >= num2)
	//	{
	//		result = num1 - num2;
	//	}
	//	else
	//	{
	//		result = num2 - num1;
	//	}
	//	cout << "number:" << result;
	//	break;
	//case 3:
	//	result = num1 * num2;
	//	cout << result;
	//	break;
	//case 4:
	//	if ((num1 || num2) == 0)
	//	{
	//		cout << "Dividing by 0 is not permited";
	//	}
	//	else
	//	{
	//		result = num1 / num2;
	//	}
	//	cout << result;
	//	break;
	//default:
	//	cout << "Invalide choice" << endl;
	//	break;
	//}*/

	//int number;
	//cin >> number;

	//if (number < 1 || number > 3000)
	//{
	//	cout << "Invalid number!" << endl;
	//	return 0;
	//}

	//if (number >= 2000) { cout << "MM"; number -= 2000; }
	//if (number >= 1000) { cout << "M"; number -= 1000; }
	//if (number >= 900) { cout << "CM"; number -= 900; }
	//if (number >= 500) { cout << "D"; number -= 500; }
	//if (number >= 400) { cout << "CD"; number -= 400; }
	//if (number >= 200) { cout << "CC"; number -= 200; }
	//if (number >= 100) { cout << "C"; number -= 100; }
	//if (number >= 90) { cout << "XC"; number -= 90; }
	//if (number >= 50) { cout << "L"; number -= 50; }
	//if (number >= 40) { cout << "XL"; number -= 40; }
	//if (number >= 20) { cout << "XX"; number -= 20; }
	//if (number >= 10) { cout << "X"; number -= 10; }
	//if (number >= 9) { cout << "IX"; number -= 9; }
	//if (number >= 5) { cout << "V"; number -= 5; }
	//if (number >= 4) { cout << "IV"; number -= 4; }
	//if (number >= 2) { cout << "II"; number -= 2; }
	//if (number >= 1) { cout << "I"; number -= 1; }

	//cout << endl;
	//return 0;
