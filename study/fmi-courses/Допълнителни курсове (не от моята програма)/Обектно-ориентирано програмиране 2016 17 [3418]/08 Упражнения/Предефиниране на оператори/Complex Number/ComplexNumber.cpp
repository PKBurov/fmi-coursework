#include <iostream>
#include <iomanip>
#include <cmath>

#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double newRe, double newIm)
	:re(newRe), im(newIm)
{}

bool operator==(const ComplexNumber& left, const ComplexNumber& right)
{
	return left.getRe() == right.getRe() && left.getIm() == right.getIm();
}

bool operator!=(const ComplexNumber& left, const ComplexNumber& right)
{
	return !(left == right);
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& right)
{
	this->re += right.re; 
	this->im += right.im;

	return *this;
}

ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right)
{
	ComplexNumber res = left;
	res += right;
	return res;
}

//ComplexNumber operator+(const ComplexNumber& left, double right)
//{
//	return left + ComplexNumber(right);
//}

ComplexNumber operator+(double left, const ComplexNumber& right)
{
	return right + left;
}

bool ComplexNumber::operator!() const
{
	return this->re == 0 && this->im == 0;
}

// функция, която намира разликата на две комплексни числа
ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& right)
{
	this->re -= right.re;
	this->im -= right.im;

	return *this;
}

ComplexNumber operator-(const ComplexNumber& left, const ComplexNumber& right)
{
	ComplexNumber res = left;
	res -= right;

	return res;
}

// функция, която умножава две комплексни числа
// резултатът остава в текущия обект
ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& right)
{
	this->re = this->re * right.re - this->im * right.im;
	this->im = this->im * right.re + this->re * right.im;

	return *this;
}

// умножение на две комплексни числа, резултатът е ново комплексно число
ComplexNumber operator*(const ComplexNumber& left, const ComplexNumber& right)
{
	ComplexNumber res = left;
	res *= right;

	return res;
}
// умножение на комплексно с реално число
//ComplexNumber operator*(const ComplexNumber& left, double right)
//{
//	return left * ComplexNumber(right);
//}
// операцията е комутативна
ComplexNumber operator*(double left, const ComplexNumber& right)
{
	return right * left;
}

// функция, която намира комплексно спрегнатото на дадено комплексно число
ComplexNumber ComplexNumber::operator-() const
{
	return ComplexNumber(this->re, -this->im);
}

ComplexNumber::operator double() const
{
	return sqrt(this->re * this->re + this->im * this->im);
}

std::ostream& operator<<(std::ostream& out, const ComplexNumber& complexNumber)
{
	out << std::setiosflags(std::ios::fixed) << std::setprecision(2);

	if(!complexNumber)
	{
		out << 0.0;
	}
	else
	{
		out << complexNumber.getRe();
		out << ((complexNumber.getIm() >= 0) ? "+" : "") << complexNumber.getIm() << ".i";
	}
	
	return out;
}

ComplexNumber& ComplexNumber::operator++()
{
	// 1 се преобразува неявно до комплексно число,
	// с помощта на конструктора...
	*this += 1;
	return *this;
}

ComplexNumber ComplexNumber::operator++(int)
{
	ComplexNumber old = *this;
	++(*this);

	return old;
}