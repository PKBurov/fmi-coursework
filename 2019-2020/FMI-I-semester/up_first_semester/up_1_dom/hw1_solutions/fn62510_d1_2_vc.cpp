/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Petar
* @idnumber 62510
* @task 2
* @compiler <VC>
*
*/
#include<iostream>
#include<limits>
using namespace std;
int main()
{
	int all_days = 0, year_counter = 0;
	do {
	//Input/Validation
		cout <<endl<< "Enter number: "; cin >> all_days;
		if (all_days == 0) { cout << "Not enought days to be considered a year or a invalid input!"; }
		if ((all_days > 0) && (all_days <= 1000000)) {break;}
		else{
			if (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
	} while (true);
	// Algorithm
	if (all_days > 365) {
		for (int i = 1; i <= all_days; i += 365) {
			++year_counter;
			if (year_counter % 4 == 0) {
				if (year_counter % 100 == 0) {
					if (year_counter % 400 == 0)
						++i;
				}
				else
					++i;
			}
		}
	//Output
		cout << "Year_counter = " << year_counter << endl;
	}
	else if ((all_days > 0) && (all_days <= 365)) {cout << "Year_counter = 1";}

	return 0;
}