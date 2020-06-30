// task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>




using namespace std;

int main()
{

	unsigned int number;
	int p;
	cout << "Please,input number:";
	cin >> number;
	int trueFalse;

	stringstream ss;
	
	ss << hex << number;
	string result = ss.str();
    cout << "The number in Hexadecimal notation:" << result << '\n';	
	trueFalse = result.find_first_not_of(result[0]) == string::npos;
	/* методът result.find_first_not_of взима първия елемент от стринга, тоест result[0] и го сравнява с всички други
       които са string::npos
       Ако не намери първия елемент никъде връща false, тоест 0
       а ако низа е съставен само от елемента на нулева позиция ще върне true, тоест 1*/
	
	if(trueFalse==1)
		cout<<"Yes!" << '\n';
	else
		cout << "No!" << '\n';
    

    return 0;
}

