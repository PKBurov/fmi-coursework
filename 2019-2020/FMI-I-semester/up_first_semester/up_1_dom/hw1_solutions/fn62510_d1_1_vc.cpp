/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Petar
* @idnumber 62510
* @task 1
* @compiler <VC>
*
*/

#include<iostream>
#include<limits>

using namespace std;
long safe_input_int(long lower_bound, long upper_bound);
void equivalent_digit_counter(int num);

int main()
{
	long number = 0;
	//Input
	cout << "This program, tells you if there are at least two repeating digits in a number!" << endl;
	cout << "Enter a valid integer input:";
	number = safe_input_int(-2147483647, 214783647);
	//Output
	if (number > 0) {
		equivalent_digit_counter(number);
	}else {
		number = number * -1;
		equivalent_digit_counter(number);
	}
return 0;
}
void equivalent_digit_counter(int num)
{
	int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0, cnt_3 = 0,
		cnt_4 = 0, cnt_5 = 0, cnt_6 = 0, cnt_7 = 0, 
		cnt_8 = 0, cnt_9 = 0, rest = 0;
	while (num != 0) {
		rest = num % 10;
		num = num / 10;
		if (rest == 0) { cnt_0++; }	if (rest == 5) { cnt_5++; }
		if (rest == 1) { cnt_1++; }	if (rest == 6) { cnt_6++; }
		if (rest == 2) { cnt_2++; }	if (rest == 7) { cnt_7++; }
		if (rest == 3) { cnt_3++; }	if (rest == 8) { cnt_8++; }
		if (rest == 4) { cnt_4++; }	if (rest == 9) { cnt_9++; }
	}
	if (cnt_0 >= 2 || cnt_1 >= 2 || cnt_2 >= 2 || cnt_3 >= 2 || cnt_4 >= 2
		|| cnt_5 >= 2 || cnt_6 >= 2 || cnt_7 >= 2 || cnt_8 >= 2 || cnt_9 >= 2) {
		cout << "In this integer there are at least two equivalent numbers" << endl;
	}else{
		cout << "In this integer there are no equivalent numbers " << endl;
	}
}
long safe_input_int(long lower_bound, long upper_bound)
{
	long long_number;
	while (true)
	{
		cin >> long_number;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Enter a valid integer input:";
			continue;
		}
		if ((long_number > lower_bound) && (long_number < upper_bound)) { break; }
	}
	return long_number;
}