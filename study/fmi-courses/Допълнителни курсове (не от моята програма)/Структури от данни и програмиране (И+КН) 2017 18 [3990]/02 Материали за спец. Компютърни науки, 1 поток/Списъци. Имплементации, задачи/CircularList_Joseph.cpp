#include "CircularList.h"

#include <iostream>

void simple_tests()
{
	CircularList<int> list;
	for (int i = 0; i < 10; ++i)
		list.push_back(i);

	std::cout << list << std::endl;

	CircularList<int> copy_list(list);
	std::cout << "copy: " << copy_list << std::endl;
	std::cout << "size: " << copy_list.size() << std::endl;

	CircularList<int>::iterator iter = list.begin();
	++iter;
	std::cout << "current element: " << *iter << std::endl;

	std::cout << "deleting the current element..." << std::endl;
	iter = list.erase(iter);
	std::cout << "after deletion: " << list << std::endl;
	std::cout << "size: " << list.size() << std::endl;
}

void josephsProblem(size_t count, size_t step)
{
	if (!count) return;

	CircularList<int> list;
	for (size_t i = 1; i <= count; ++i)
	{
		list.push_back(i);
	}

	std::cout << "The beginning: " << list << std::endl;

	CircularList<int>::iterator iter = list.begin();
	while (list.size() > 1)
	{
		// стъпките са с една по-малко
		for (size_t i = 1; i < step; ++i)
		{
			++iter;
		}

		std::cout << *iter << ' ';
		iter = list.erase(iter);
	}

	std::cout << "The last man standing is " << *iter << std::endl;
}

// #include "CircularList_Tests.h"

int main()
{
	josephsProblem(41, 3);
	// RunTests();
	return 0;
}