#include <iostream>
#include <string>
#include "MyString.h"

int main() {

	MyString String;
	std::cout << "Enter stuff here:" << "\n";
	std::cin >> String;
	std::cout << "\n";
	std::cout << String;
	std::cout << "\n";

	return 0;
}