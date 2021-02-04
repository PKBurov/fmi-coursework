#pragma once
#include<iostream>
class IntCounter
{
private:
	int r_Count = 0;
	unsigned int a_Size;
	int* a_Buffer;

public:
	//Constructor:
	IntCounter(const int* size);
	//Copy Constructor:
	IntCounter(IntCounter& other);
	//Destructor:
	~IntCounter();
	//Operators:

	//Methods:
	int get_count() const;

};

