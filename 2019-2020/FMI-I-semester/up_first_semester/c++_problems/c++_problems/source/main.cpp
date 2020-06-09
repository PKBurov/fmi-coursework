//#include<iostream>
//#include<string>
//#define MAXLINE 1000    /* maximum input line length */
//using namespace std;
////------------------------------------------Book functions
//int getline(char line[], int max);
//int strindex(char source[], char searchfor[]);
//
////-------------------------------------------My functions ( mestata suvpadat s funciite)
//void swap(int num1, int num2);
//void print_string(std::string data);
//enum Days;
//void print_day(enum Days day);
//const char* PrintDay(enum Days day);
//void print_day(enum Days day);
//int pyramid(int number);
//
////--------------------------------------------------------------
//
//int main() 
//{
//	int arr[] = { 1,2,3,4,5 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	cout << len;
//	
//
//
//
//
//
////-----------Loops------------
//
//			//6
//	/*int num;
//	std::cout << "Vuvedete chislo: ", std::cin >> num;
//
//	for (int i = 1; i <= num; i++)
//	{
//		if (num % i == 0)
//		{
//			std::cout << num / i << std::endl;
//		}
//	}*/
//
//			//5
//	/*int num;
//	std::cout << "Vuvedete chislo: ", std::cin >> num;
//
//	for (int i = 1; i <= num; i++)
//	{
//		if (num % i == 0)
//		{
//			std::cout << num / i << std::endl;
//		}
//	}*/
//
//
////-----------------------------------------
//
//	//Days day;
//	//std::cout << PrintDay(Thursday);
//	//int factoriel, proiz = 0;
//	//std::cout << "Factorial of:", std::cin >> factoriel;
//	//for (int i = 1; i <=factoriel; i++)
//	//{
//	//	proiz = i * factoriel;
//	//	//std::cout << "Number:" << i << std::endl;
//	//}
//	//std::cout << "=" << proiz << std::endl;
//	//std::cin.get();
//	//
////--------------------------------Zadachi ot Lybo/Vankata
//	/*int num1, num2;
//	char choice;
//	std::cout << "Calculator!" << std::endl;
//	std::cout << "Vuvedete a= ", std::cin >> num1;
//	std::cout << "Vuvedete b= ", std::cin >> num2;
//	std::cout << "Izberete: +, -, / , %" << std::endl;
//		std::cin >> choice;
//
//		switch (choice)
//		{
//		case'+':
//			std::cout << "The sum is =" << num1 + num2 << std::endl;
//				break;
//		case'-':
//			if (num1>=num2)
//			{
//				std::cout << "The - is =" << num1 - num2 << std::endl;
//			}
//			else
//			{
//				std::cout << "The - is =" << num2 - num1 << std::endl;
//			}
//			break;
//		case'/':
//			std::cout << "The / is =" << num1/num2 << std::endl;
//			break;
//
//		case'%':
//			std::cout << "The sum is =" << num1 % num2 << std::endl;
//			break;
//
//		default: std::cout << "Ne ste vuveli chislo";
//			break;
//		}*/
//
//	//std::cout << getDayName(Monday);
//	//print_day(Monday);
//	//print_string("Monday");
//	
//	//swap(5,3);
//	//print_day(1);
//
//	/*int year;
//	std::cout << "Enter year:";
//	std::cin >> year;
//	if (year % 2 == 0) {
//		std::cout << year << " is a leap year";
//	}else {
//		std::cout << year << "is not a leap year";
//	}*/
////---------------------------------------------
//	
//	////find all lines matching pattern //char pattern[] = "ould";    // pattern to search for 
//
//	//	char line[MAXLINE];
//	//	int found = 0;
//
//	//	while (getline(line, MAXLINE) > 0)	/* getline:  get line into s, return length */
//	//	{
//	//		if (strindex(line, pattern) >= 0)
//	//		{
//	//			std::cout << line;
//	//			found++;
//	//		}
//	//	}
//	//	return found;
//}
////
////void swap(int num1, int num2)
////{
////	num1 = num1 + num2;
////	num2 = num1 - num2;
////	num1 = num1 - num2;
////
////	std::cout << "num1 = " << num1, std::cout << " num2 =" << num2;
////}
////void print_day_other(int num)
////{
////	if (num == 1) { std::cout << "Monday" << std::endl; }
////	if (num == 2) { std::cout << "Tuesday" << std::endl; }
////	if (num == 3) { std::cout << "Thursday" << std::endl; }
////	if (num == 4) { std::cout << "Wendsday" << std::endl; }
////	if (num == 5) { std::cout << "Friday" << std::endl; }
////	if (num == 6) { std::cout << "Saturday" << std::endl; }
////	if (num == 7) { std::cout << "Sunday" << std::endl; }
////
////}
////void print_string(std::string data)
////{
////	if (data == "Monday") { std::cout << "Monday" << std::endl; }
////	if (data == "Tuesday") { std::cout << "Tuesday" << std::endl; }
////	if (data == "Thursday") { std::cout << "Thursday" << std::endl; }
////	if (data == "Wendsday") { std::cout << "Wendsday" << std::endl; }
////	if (data == "Friday") { std::cout << "Friday" << std::endl; }
////	if (data == "Saturday") { std::cout << "Saturday" << std::endl; }
////	if (data == "Sunday") { std::cout << "Sunday" << std::endl; }
////}
////enum Days  
////{
////	Monday = 1, Tuesday, Thursday, Wensday, Frieday, Saturday, Sunday
////};
////const char* PrintDay(enum Days day)
////{
////	switch (day)
////	{
////	case Monday:return "Monday";
////	case Tuesday:return "Tuesday";
////	case Thursday:return "Thursday";
////	case Wensday:return "Wensday";
////	case Frieday:return "Frieday";
////	case Saturday:return "Saturday";
////	case Sunday:return "Sunday";
////	}
////}
////void print_day(enum Days day)
////{
////	std::cout << PrintDay(day);
////}
////int pyramid(int number) 
////{
////	int num = 1, count = 0;
////	for (int i = 1; i <= number; i++)
////	{
////		//print * equal to row number
////		for (int j = 1; j <= i; j++)
////		{
////			if(true){std::cout << i;}
////		}
////		std::cout << "\n";
////	}
////	return 0;
////}
//////-----------------------------------------------Book functions
////int strindex(char s[], char t[])
////{
////	int i, j, k;
////
////	for (i = 0; s[i] != '\0'; i++) 
////	{
////
////		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
////		{
////			if (k > 0 && t[k] == '\0')
////			{
////				return i;
////			}
////		}
////	}
////	return -1;
////}
////int getline(char s[], int lim)
////{
////	int c, i;
////	i = 0;
////
////	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
////	{
////		s[i++] = c;
////
////		if (c == '\n')
////		{
////			s[i++] = c;
////			s[i] = '\0';
////		}
////	}
////	return i;
////}
///*---------------------------------------------- strindex:  return index of t in s, −1 if none */