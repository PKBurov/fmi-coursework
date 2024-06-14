#include <iostream>
#include <iomanip>

#include "ComplexNumber.h"

void read(ComplexNumber& cn)
{
	std::cin >> cn.re >> cn.im;
}

void print(const ComplexNumber& cn)
{
	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2);
	std::cout << cn.re;
	std::cout << ((cn.im >= 0) ? " + " : " ") << cn.im << ".i" << std::endl;
}

// функция, която проверява дали две комплексни числа са равни
bool equal(const ComplexNumber& left, const ComplexNumber& right)
{
	return left.re == right.re && left.im == right.im;
}

// функция, която намира сумата на две комплексни числа
ComplexNumber sum(const ComplexNumber& left, const ComplexNumber& right)
{
	ComplexNumber result;
	result.re = left.re + right.re;
	result.im = left.im + right.im;

	return result;
}

// функция, която намира разликата на две комплексни числа
ComplexNumber substract(const ComplexNumber& left, const ComplexNumber& right)
{
	ComplexNumber result;
	result.re = left.re - right.re;
	result.im = left.im - right.im;

	return result;
}
// функция, която умножава две комплексни числа
ComplexNumber product(const ComplexNumber& left, const ComplexNumber& right)
{
	ComplexNumber result;
	result.re = left.re*right.re - left.im*right.im;
	result.im = left.im*right.re + left.re*right.im;

	return result;
}

// функция, която намира комплексно спрегнатото на дадено комплексно число
ComplexNumber conjugate(const ComplexNumber& cn)
{
	ComplexNumber conjugateNumber;
	conjugateNumber.re = cn.re;
	conjugateNumber.im = -cn.im;

	return conjugateNumber;
}

