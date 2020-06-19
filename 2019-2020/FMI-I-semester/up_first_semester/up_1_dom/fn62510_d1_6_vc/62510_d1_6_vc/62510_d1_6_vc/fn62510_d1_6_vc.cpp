/* fn62510_prob6_vc.cpp : Defines the entry point for the console application.
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @idnumber 62510
* @task 6
* @compiler VC
*/
#include<iostream>
#include<limits>
using namespace std;

int main()
{
	double x_cord = 0, y_cord = 0, dot_distance = 0;
	//Input
	do {
		cout << "Enter the X and Y coordinates:"; cin >> x_cord; cin >> y_cord;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else{break;}
	} while (true);

	//Formula
	dot_distance = ((abs(x_cord) * abs(x_cord))+(abs(y_cord) * abs(y_cord)));

	//Output
	if (abs(x_cord) < 1 && abs(y_cord) < 1) {
		cout << "Black";
	}else if (abs(x_cord) == 1 && abs(y_cord) <= 1) {
		cout << "Undifined";
	}else if (abs(y_cord) == 1 && abs(x_cord) <= 1) {
		cout << "Undifined";
	}else if (dot_distance < 4) {
		cout << "White";
	}else if (dot_distance > 4 && dot_distance < 9) {
		cout << "Black";
	}else if (dot_distance == 4) {
		cout << "Undefined";
	}else if (dot_distance > 9) {
		cout << "Outside";
	}else if (dot_distance < 9){
		cout << "Black";
	}else if (dot_distance == 9){
		cout << "Undifined";
	}
	return 0;
}