/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Petar
* @idnumber 62510
* @task 4
* @compiler <VC>
*
*/

#include<iostream>
#include<limits>
using namespace std;

int main()
{
	int number = 0;
	double sleep = 0;
	//Input check
	do {
		cout << "Enter a number between [1 , 2^16 -1]: "; cin >> number;
		if (number >= 1 && number <= 65535) {break;
		}else if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	} while (true);
	//Output
	for  (;number != 0;){
		cout << "Timer: " << number;
		for (int i = 0; i < 1000000000; i++) { sleep = number / 2;}
		number--;
		system("cls");
	}
	cout << endl << endl;
	return 0;
}
