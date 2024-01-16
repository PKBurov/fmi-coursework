#include <iostream>
#include <cmath>

#include "Point.h"

Point::Point(double newX, double newY)
{
	std::cout << "\n Creating point ";

	this->setX(newX);
	this->setY(newY);

	// извеждане на координатите на новата точка
	this->print();
}

void Point::print() const
{
	std::cout << "( " << this->getX() << ", " << this->getY() << " )" << std::endl;
}

double Point::distance(const Point& other) const
{
	return sqrt((other.getX() - this->getX())*(other.getX() - this->getX()) + 
		(other.getY() - this->getY())*(other.getY() - this->getY()));
}