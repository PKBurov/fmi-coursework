#include <iostream>
#include "Date.h"

Date::Date() : day(1), month(1), year(1900)
{}

// използваме инициализиращия списък, за да дадем първоначално
// валидни стойности на член-данните, 
// в мутаторите датата не се променя, ако с подадения аргумент
// не се получава валидна дата...
Date::Date(unsigned day, unsigned month, unsigned year) 
	: day(1), month(1), year(1900)
{
	this->setDay(day);
	this->setMonth(month);
	this->setYear(year);

	//if(isValid(d, m, y))
	//{
	//	this->day = d;
	//	this->month = m;
	//	this->year = y;
	//}
}

// деструктор
Date::~Date()
{
	std::cout << "~Date: ";
	this->print();
}

void Date::print() const
{
	std::cout << this->getDay() << '.' << this->getMonth() << '.' << this->getYear() << std::endl;
}

bool Date::isLeapYear(unsigned year) const
{
	return (year % 4 == 0) && !(year % 100 == 0 && year % 400 != 0);
}

bool Date::isValid(unsigned day, unsigned month, unsigned year) const
{
	if(!year) return false;

	if(month < 1 || month > 12) return false;

	unsigned maxDays;
	switch(month)
	{
		case 2: maxDays = 28 + isLeapYear(year); break;
		case 4:
		case 6:
		case 9:
		case 11: maxDays = 30; break;
		default:
			maxDays = 31;
			break;
	}

	return day > 0 && day <= maxDays;
}

// ако датата, която се образува с новия ден не е валидна,
// не променяме текущата дата
void Date::setDay(unsigned newDay)
{
	if(isValid(newDay, this->month, this->year))
		this->day = newDay;
}

void Date::setMonth(unsigned newMonth)
{
	if(isValid(this->day, newMonth, this->year))
		this->month = newMonth;
}

void Date::setYear(unsigned newYear)
{
	if(isValid(this->day, this->month, newYear))
		this->year = newYear;
}
