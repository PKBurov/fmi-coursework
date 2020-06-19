/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Petar
* @idnumber 62510
* @task 3
* @compiler <VC>
*
*/

#include<iostream>
#include<limits>

using namespace std;
void hex(int result);

int main()
{
	char char_num1 = 0, char_num2 = 0, operation = 0;
	int char_to_int1 = 0, char_to_int2 = 0, result = 0;

	//Input
	do{	
		cout << "Enter first the arithmatic operation (+, -, *, /, %) and then both operands: "; cin >> operation; cin >> char_num1; cin >> char_num2;
		if (((operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '%'))
			&& (((char_num1 >= '0' && char_num1 <= '9') || (char_num1 >= 'A' && char_num1 <= 'F'))
			&& ((char_num2 > '0' && char_num2 <='9') || (char_num2 >= 'A' && char_num2 <= 'F')))) {break;
		}else {
			cin.fail();
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	} while (true);

	//From Char to Int
	char_to_int1 = char_num1; char_to_int2 = char_num2;
	if (char_num1 >= '0' && char_num1 <= '9') { char_to_int1 = char_to_int1 - '0'; }	if (char_num1 >= 'A' && char_num1 <= 'F') { char_to_int1 = char_to_int1 - '7'; }
	if (char_num2 >= '0' && char_num2 <= '9') { char_to_int2 = char_to_int2 - '0'; }	if (char_num2 >= 'A' && char_num1 <= 'F') { char_to_int2 = char_to_int2 - '7'; }

	//Output
	switch (operation){
	case '+':
		result = char_to_int1 + char_to_int2;
		cout << "Number is : "; hex(result);
		break;
	case '-':
		result = char_to_int1 - char_to_int2;
		if (result == 0){cout << "Number is: 0" << endl; 
		}else if (result < 0){
			result = result * -1;
			cout << "Number is: -"; hex(result);
		}else{cout << "Number is: "; hex(result);}
		break;
	case '*':
		result = char_to_int1*char_to_int2;
		if (result == 0) {cout << "Number is: 0";
		}else
			cout << "Number is: "; hex(result);
		break;
	case '/':
		result = char_to_int1 / char_to_int2;
		if (result == 0) {cout << "Number is: 0";
		}else
			cout << "Number is: "; hex(result);
		break;
	case '%':
		result = char_to_int1 % char_to_int2;
		if (result == 0){cout << "Number is: 0";
		}else
		cout << "Number is: "; hex(result);
		break;
	}
	return 0;
}
void hex(int result)
{
	int decimal = 0, storing_num = 0, four_d_num = 0, equal_res = 0, temp_number = 0;
	char in_hex=0;

	for (equal_res = result; equal_res > 0; equal_res = equal_res / 16)	
	{
		temp_number = equal_res % 16; // Takes in the remainder of the value
		if (temp_number < 10)
			temp_number = temp_number + 48; // if < 10 then +48 to cover the 0-9 digits in char 
		else
			temp_number = temp_number + 55; // else +55 to cover A-F values in char;
		four_d_num = four_d_num * 100 + temp_number; // Multyplie the first int(char value) by *100 and sum the rest of the int(char value)
	}
	for (storing_num = four_d_num; storing_num > 0; storing_num = storing_num / 100)
	{
		in_hex = storing_num % 100; //  Takes the last 2 digits of the 4lenght number and then the first 2digits
		cout << (char)in_hex; //cast to char
	}
	cout << endl << endl;
}