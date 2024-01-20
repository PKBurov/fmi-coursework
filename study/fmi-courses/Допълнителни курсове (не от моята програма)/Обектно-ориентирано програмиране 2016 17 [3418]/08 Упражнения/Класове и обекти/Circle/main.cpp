#include <iostream>

#include "Point.h"
#include "Circle.h"


// Да се създаде масив от окръжности. 
// Да се изведат окръжностите, които съдържат дадена точка.
// Да се 

int main()
{
	// (0, 0)
	Point center;

	// (1, 0)
	Point p(1);

	// p.setX(1);
	// p.setY(2);

	std::cout << "Using default constructor for circle: " << std::endl;
	Circle c;

	std::cout << "Using the constructor with arguments: " << std::endl;
	Circle c1(p, 1);

	std::cout << "Invalid value for the radius: " << std::endl;
	Circle c2(p, -1);

	return 0;
}