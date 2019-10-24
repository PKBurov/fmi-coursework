#include<iostream>
#include<cmath>


int main()
{
	
}







//void binary (int num1);
//void hex (int num1);
//void octa (int num1);
//
//int main()
//{
//	int user_num;
//	char choice;
//
//	std::cout << "Number: ", std::cin >> user_num, std::cout << std::endl;
//
//	std::cout << "Choose: b-binary, h-hex, o-octal: ", std::cin >> choice;
//
//	switch (choice)
//	{
//	case 'b':
//		binary(user_num);
//		break;
//	case 'h':
//		hex(user_num);
//		break;
//	case 'o':
//		octa(user_num);
//		break;
//	default:
//		std::cout << "Try again" << std::endl;
//		break;
//	}
//		std::cin.get();
//}
//
//void binary(int num1)
//{
//	int binary_num[32];
//	int i = 0;
//	int flag = 0;
//
//	if (num1<0)
//	{
//		num1 = (-1)*num1;
//		flag = 1;
//	}
//	while (num1 > 0)
//	{
//		binary_num[i] = num1 % 2;
//		num1 = num1 / 2;
//		i++;
//	}
//	if (flag == 1)
//	{
//		std::cout << "-";
//	}
//	for (int j = i - 1; j >= 0; j--)
//		std::cout << binary_num[j];
//}
//void hex(int num1)
//{
//	int hex_num[32];
//	int i = 0;
//	int flag = 0;
//
//	if (num1 < 0)
//	{
//		num1 = (-1) * num1;
//		flag = 1;
//	}
//	while (num1 > 0)
//	{
//		hex_num[i] = num1 % 16;
//		num1 = num1 / 16;
//
//		i++;
//	}
//	if (flag == 1)
//	{
//		std::cout << "-";
//	}
//	for (int j = i - 1; j >= 0; j--) ///ne se seshtam sega;
//	{
//		if (hex_num[j] == 10) { std::cout << "A"; }
//		if (hex_num[j] == 11) { std::cout << "B"; }
//		if (hex_num[j] == 12) { std::cout << "C"; }
//		if (hex_num[j] == 13) { std::cout << "D"; }
//		if (hex_num[j] == 14) { std::cout << "E"; }
//		if (hex_num[j] == 15) { std::cout << "F"; }
//
//		std::cout << hex_num[j];
//	}
//		
//}
//void octa(int num1)
//{
//	int octa_num[32];
//	int i = 0;
//	int flag = 0;
//
//	if (num1 < 0)
//	{
//		num1 = (-1) * num1;
//		flag = 1;
//	}
//	while (num1 > 0)
//	{
//		octa_num[i] = num1 % 8;
//		num1 = num1 / 8;
//		i++;
//	}
//	if (flag == 1)
//	{
//		std::cout << "-";
//	}
//	for (int j = i - 1; j >= 0; j--)
//		std::cout << octa_num[j];
//}