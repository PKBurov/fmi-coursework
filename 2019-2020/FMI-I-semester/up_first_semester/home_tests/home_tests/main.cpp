#include <iostream>
using namespace std;

class school
{
public:
	char name = 0, gender = 0;
	int school_number = 0, date_of_birth = 0, age = 0; 

	void print_info(int school_number,int date_of_birth,int age)
	{
		
		cout << school_number << endl;
		cout << date_of_birth << endl;
		cout << age << endl;
	}

};



//#include <string>
//#define lenght 1000
//using namespace std::string_literals;
//
//void string_cop_return( std::string& name)
//{
//	std:: string name1;
//	char str[lenght];
//	std::cout<< "Vuvedi string: ";
//	std::cin.get(str, lenght);
//	std::cout << "Copy: " << str;
//	
//}


int main()
{
	school player;
	cout << "Hi"<<endl;

	player.print_info(9841234, 12051999, 20);


}


	//int function(int num1, int num2, int num3, int num4, int num5,int num6)
//{
//	int arr[3] = { num1,num2,num3 };
//	int arr2[3] = { num4,num5,num6 };
//	int array_one_processed[3];
//
//	for (int i = 0; i < 3; i++)
//	{
//		array_one_processed[i] = arr[i] + arr2[i];
//		std::cout << " " << array_one_processed[i];
//	}
//	return 0;
//}
//int main()
//{
//	function(1, 2, 3, 4, 5, 6);
//	std::cin.get();
//}
	
	/*int sum = 0;
	std::cout << "Izberi suma: ", std::cin >> sum;
if (sum%2==0)
{
	std::cout << "V dqsnata ruka ima cheten broi";
}
else
{
	std::cout << "V lqvata ruka imash cheten broi";
}*/

	/*char letter, nue;
	std::cout << "Vuvedete bukva: ", std::cin >> letter;

	if (letter>=65 && letter <= 97){
		std::cout << char(letter + 32);
	}
	if (letter >= 97 && letter <= 122)
	{
		std::cout << char(letter -32);
	}

	std::cout <<"\t"<< char(63);*/

	/*int center,radius, num;
	std::cout << "Vuvete centara na tochkata k(p,r) = ", std::cin >> center;
	std::cout << "Vuvete radiusa na tochkata k(p,r) = ", std::cin >> radius;

	std::cout << "Vuvedete tochkata K(0,r) = ", std::cin >> num;

	if (num > radius) { std::cout << "Tochkata e vun ot okrujnosta"; }
	if (num < radius) { std::cout << "Tochkata e vutre v okrujnosta"; }
	if (num == radius) { std::cout << "Tochkata e na okrujnosta"; }


	std::cin.get();*/

	/*int radius, num;
	std::cout << "Vuvete radius na tochkata k(0,r) = ", std::cin >> radius;
	std::cout << "Vuvedete tochkata K(0,r) = ", std::cin >> num;

	if (num > radius) { std::cout << "Tochkata e vun ot okrujnosta"; }
	if (num < radius) { std::cout << "Tochkata e vutre v okrujnosta"; }
	if (num == radius) { std::cout << "Tochkata e na okrujnosta"; }
	*/

	/*//-------------------------purva zadacha
int num, fir, sec, thrd;
std::cout << "Vuvedete tricifreno chislo:";
std::cin >> num;

fir = num / 100 % 5;
sec = num / 10 % 10;
thrd = num % 10;

if (fir == 0 || sec == 0 || thrd == 0)
{
	std::cout << "V chisloto ima '0'";
}
else
{
	if (num % fir == 0) { std::cout << fir << std::endl; }
	if (num % sec == 0) { std::cout << sec << std::endl; }
	if (num % thrd == 0) { std::cout << thrd << std::endl;; }
}
*/

	/*int num1, num2, number;
	std::cout << "Vuvedete dve chisla:" << std::endl;
	std::cout << "First nubmer:"; std::cin >> num1;
	std::cout << "Second nubmer:"; std::cin >> num2;

	std::cout << "Larger number: " << ((num1 + num2) + abs(num1 - num2)) / 2 << std::endl;*/
	
	/*int num1, num2, num3;
	
	std::cout << "Vuvedete chislo za stranata a: ", std::cin >> num1;
	std::cout << "Vuvedete chislo za stranata b: ", std::cin >> num2;
	std::cout << "Vuvedete chislo za stranata c: ", std::cin >> num3;

	if ((num1+num2)> num3 && (num1+num3) > num2 && (num3+num2) >num1)
	{
		if ( (num1^2)+ (num2^2) == (num3^2)) { std::cout << "pravoagalen"; }
		if (num1==num2 || num2==num3 || num1==num3) { std::cout << "Ravnobedren"; }
		if (num1 == num2 == num3) { std::cout << "Ravnostranen"; }
	}
	else
	{
		std::cout << "Nqma takuv triagulnik" << std::endl;
	}*/

	/*int num, part1,part2;
	std::cout << "Vuvedete chislo mejdu intervala [1000..9999]: ",std::cin >> num;
	part1 = num / 100;
	part2 = num % 100;
	if (part1 == part2) { std::cout << "Da"; }
	else
	{
		std::cout << "NE";
	}*/

	/*int choice;
	std::cout << "Vuvedete chislo=mesec ako dnite sa chetni shte se izpishi i sledvashiq: ", std::cin >> choice;

	switch (choice)
	{
	case 1:
		std::cout << "Qnuari-31";//ako e cheten bez breik i gotovo;
		break;

	default:
		std::cout << "Ne ste vuveli nishto";
		break;
	}*/
	
