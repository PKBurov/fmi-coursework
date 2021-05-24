#include<iostream>
#include"IntCounter.h"
int main() {

	int* some_number = new int(5);
	IntCounter<int> first(some_number);
	std::cout << first.get_count() << std::endl;
	IntCounter<int> second = first;
	std::cout << first.get_count() << std::endl;

	{
		IntCounter<int> third(second);
		std::cout << first.get_count() << std::endl;
	}
	std::cout << first.get_count() << std::endl;

	std::cin.get();
}