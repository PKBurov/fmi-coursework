#include <iostream>
#include <iomanip>

#include "ComplexNumber.h"

// шаблон за дефиниране на член-функция на клас
// <тип_на_резултата> <на_кой_клас_принадлежи>::<име_на_функцията>(<аргументи>)[const]

// конструктор по подразбиране
ComplexNumber::ComplexNumber()
{
	this->re = 0;
	this->im = 0;
}

// конструктор с параметри
ComplexNumber::ComplexNumber(double newRe, double newIm)
{
	this->re = newRe;
	this->im = newIm;
}

void ComplexNumber::print() const
{
	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2);
	std::cout << this->re;
	std::cout << ((this->im >= 0) ? " + " : " ") << this->im << ".i" << std::endl;
}

// функция, която проверява дали две комплексни числа са равни
bool ComplexNumber::equals(const ComplexNumber& other) const
{
	return this->re == other.re && this->im == other.im;
}

// функция, която намира сумата на две комплексни числа
ComplexNumber ComplexNumber::add(const ComplexNumber& other) const
{
	return ComplexNumber(this->re + other.re, this->im + other.im);
}

// функция, която намира разликата на две комплексни числа
ComplexNumber ComplexNumber::substract(const ComplexNumber& other) const
{
	return ComplexNumber(this->re - other.re, this->im - other.im);
}
// функция, която умножава две комплексни числа
ComplexNumber ComplexNumber::multiply(const ComplexNumber& other) const
{
	return ComplexNumber(this->re*other.re - this->im*other.im,
						 this->im*other.re + this->re*other.im);
}

// функция, която намира комплексно спрегнатото на дадено комплексно число
ComplexNumber ComplexNumber::conjugate() const
{
	return ComplexNumber(this->re, -this->im);
}

