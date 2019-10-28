#include<iostream>
#include<iomanip>
int main()
{

	std::cout << 62510 % 2019 << std::endl;

	/*int n_term = 0, sum = 0, sum1 = 0, f;

	std::cout << "bu="; std::cin >> n_term;

	for (int i = 1; i <= n_term; i++)
	{
		sum = sum + i;
		f = n_term - i;
		for (int k = 0; k <= f ; k++)
		{
			sum1 = sum1 + k;
		}
	}
	std::cout << "NE= "<< sum + sum1 << std::endl;*/
	
	/*std::cout << "Prog n_th term series sum" << std::endl;
	std::cout << "Chislo= ", std::cin >> n_term;


	for (int i = 1; i <= n_term; i++)
	{
		tsum = 0;
		for (int j = 1; j <= i; j++)
		{
			sum += j;
			tsum += j;
			std::cout << j;
			if (j < i)
			{
				std::cout << "+";
			}
		}
		std::cout << " = " << tsum << std::endl;
	}
	std::cout << " The sum of the above series is: " << sum <<std::endl;
	
	std::cout << " = " << sum;*/

	std::cin.get();
}