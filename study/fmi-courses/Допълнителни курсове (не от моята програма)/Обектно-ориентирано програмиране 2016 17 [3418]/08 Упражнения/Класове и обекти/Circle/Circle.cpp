#include <iostream>

#include "Circle.h"

Circle::Circle() : radius(0)
{
	// за инициализиране на член-данната center 
	// се използва подразбиращият се контруктор на Point

	// ако не съществува конструктор по подразбиране в класа Point, 
	// то:
	// 1) ако няма дефиниран нито един конструктор, 
	// то се генерира системен подразбиращ се, 
	// който ще инициализира данните с подразбиращи се стойности;
	// 2) ако има дефиниран конструктор с аргумент (без стойности по подразбиране),
	// се получава съобщение за грешка, че не е използван подходящ конструктор

	std::cout << "\nCircle with ";
	this->print();
	std::cout << "was created!" << std::endl;
}

//Circle::Circle(const Point& c, double r)
//{
//	// вече в тялото на конструктора Circle, обектът center е създаден
//	// за него се използва подразбиращ се конструктор
//
//	// променяма центъра, като използваме новите стойности
//	this->setCenter(c);
//
//	// да се провери стойността на r!!!
//	this->setRadius(r);
//
//	std::cout << "\nCircle with ";
//	this->print();
//	std::cout << "was created!" << std::endl;
//}

// за да се избегнат двете стъпки при инициализиране на вградения обект,
// той трябва да бъде инициализиран в т.нар. инициализиращ списък
// (такъв имат само конструкторите)
Circle::Circle(const Point& c, double r) : center(c), radius(0)
{
	// ако се използва невалидна стойност за радиуса,
	// radius получава случайна стойност
	// за да се избегне това, в инициализиращия списък може да се добави
	// инициализиране на радиуса с 0
	this->setRadius(r);

	std::cout << "\nCircle with ";
	this->print();
	std::cout << "was created!" << std::endl;
}

void Circle::setCenter(const Point& c)
{
	center = c;
}

void Circle::setCenter(double x, double y)
{
	center.setX(x);
	center.setY(y);
}

void Circle::setRadius(double r)
{
	if (r >= 0)
		radius = r;
}

void Circle::print() const
{
	std::cout << "\n Center: ";
	center.print();
	std::cout << " r = " << radius << std::endl;
}
