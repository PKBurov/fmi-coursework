#include <iostream>

#include "Set.h"

int main()
{
	Set set(5);

	for(size_t i = 0; i < 5; ++i)
		set += i;

	std::cout << set << std::endl;

	int elem = 4;
	std::cout << "Is " << elem << " in the set? : " << std::boolalpha << set(elem) << std::endl;

	set += elem;
	std::cout << "Add " << elem << " to the set: " << set << std::endl;

	set -= elem;
	std::cout << "Remove " << elem << " from the set: " << set << std::endl;

	Set copySet = set;
	std::cout << "Copy: " << copySet << std::endl;

	Set emptySet;
	
	std::cout << "Intersection between " << set << " and " << emptySet << ": ";
	set *= emptySet;
	std::cout << set << std::endl;

	std::cout << "Is " << set << " equal to " << emptySet << "?: " << (set == emptySet) << std::endl;

	Set newSet = set + 5;
	newSet += 3;

	std::cout << "Intersection between " << newSet << " and " << copySet << ": ";
	newSet *= copySet;
	std::cout << newSet << std::endl;

	std::cout << "Difference between " << copySet << " and " << newSet << ": ";
	copySet -= newSet;
	std::cout << copySet << std::endl;

	return 0;
}