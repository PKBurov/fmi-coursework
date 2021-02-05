#include<iostream>
#include"IntCounter.h"

int main() {
	
	// Test:

	int* some_number = new int(5);
	IntCounter first(some_number);						
	std::cout << first.get_count() << std::endl;
	IntCounter second = first;
	std::cout << first.get_count() << std::endl;
	{
		IntCounter third(second);
		std::cout << first.get_count() << std::endl;
	}
	std::cout << first.get_count() << std::endl;

	/*
	1
	2
	3
	2
	*/
	

	/*int* some_number = new int(5);
	IntCounter first(some_number);

	int* some_other_number = new int(7);
	IntCounter second(some_other_number);

	std::cout << first.get_count() << std::endl;
	std::cout << second.get_count() << std::endl;
	*/

	/*
	1
	1
	*/

	std::cin.get();
}