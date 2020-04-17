/* fn62510_prob3_vc.cpp : Defines the entry point for the console application.
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
*
* @idnumber 62510
* @task 5
* @compiler VC
*/
#include<iostream>
#include<cmath>
#include<limits>

using namespace std;
double safe_input_int(double lower_bound, double upper_bound);
int main()
{
	double fst_par = 0, scn_par = 0, thrd_par = 0, discriminant = 0, fst_root = 0, scn_root = 0;

	//Input
	cout << "Program to calculate ax^4 + bx^2 + c = 0" << endl;
	cout << "Enter value for parameter 'a' = ";
	fst_par = safe_input_int(DBL_MIN, DBL_MAX);
	cout << "Enter value for parameter 'b' = ";
	scn_par = safe_input_int(DBL_MIN, DBL_MAX);
	cout << "Enter value for parameter 'c' = ";
	thrd_par = safe_input_int(DBL_MIN, DBL_MAX);

	//Formulas
	discriminant = (scn_par * scn_par) +(-4 * (fst_par * thrd_par));
	fst_root = (-(scn_par) + sqrt(discriminant)) / (2 * fst_par);
	scn_root = (-(scn_par) - sqrt(discriminant)) / (2 * fst_par);

	if (discriminant > 0){
		if (fst_root<0){
			cout << "No real roots for first root!" << '\t';;
		}else{
			fst_root = sqrt(fst_root);
			cout << "The first root = " << fst_root << '\t';
		}if (scn_root < 0){
			cout << "No real roots for second root!";
		}else{
			scn_root = sqrt(scn_root);
			cout << "The second root = " << scn_root << endl;
		}
		cout << endl << endl;
	}
	else if (discriminant == 0){
		if (fst_root < 0) {
			cout << "No real roots for second root!";
		}else 
			fst_root = sqrt(fst_root);
			cout << endl<< "The first root is equal to the second root = " << fst_root << endl;
	}else{
		cout << "This bi-quadratic equation has no real roots!" << endl;
	}
	return 0;
}
double safe_input_int(double lower_bound, double upper_bound)
{
	double double_number;
	while (true)
	{
		cin >> double_number;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Enter a valid input for this parameter:";
			continue;
		}
		if ((double_number > lower_bound) && (double_number < upper_bound)) {break;}
	}
	return double_number;
}