/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Silvia Ivanova
 * @idnumber 61999
 * @task 3
 * @compiler GCC
 *
 */



#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>




using namespace std;

int main()
{

	unsigned int number;
	int p;

	cin >> number;
	int trueFalse;

	stringstream ss;

	ss << hex << number;
	string result = ss.str();


	trueFalse = result.find_first_not_of(result[0]) == string::npos;


	if(trueFalse==1)
		cout<<"Yes" << '\n';
	else
		cout << "No" << '\n';


    return 0;
}
