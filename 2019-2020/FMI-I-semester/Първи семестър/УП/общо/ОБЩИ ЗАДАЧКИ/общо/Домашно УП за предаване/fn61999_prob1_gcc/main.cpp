/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Silvia Ivanova
 * @idnumber 61999
 * @task 1
 * @compiler GCC
 *
 */


#include<iostream>
#include <string>

using namespace std;


int main()
{
string units[10] = {"","I","II", "III","IV", "V", "VI", "VII", "VIII","IX" };

string dozens[10] = { "","X","XX", "XXX","XL", "L", "LX", "LXX", "LXXX","XC" };

string hundreds[10] = { "","C","CC", "CCC","CD", "D", "DC", "DCC", "DCCC","CM" };

string thousandths[4] = { "","M","MM", "MMM"};

	int number,th,hundr,dz,un;

string result;


cin >> number;


if (number >= 5000)

cout << "Invalid number!";

else

{

th = number / 1000;

result = thousandths[th];



hundr = number / 100;

hundr = hundr % 10;

result += hundreds[hundr];



dz = number / 10;

dz = dz % 10;

result += dozens[dz];



un = number % 10;

result += units[un];

}


cout << result << '\n';


    return 0;
}
