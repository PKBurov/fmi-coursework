#include <iostream>

#include "ComplexNumber.h"

int main()
{
	ComplexNumber left;
	ComplexNumber right(3, 5);

	std::cout << left << " + " << right << " = " << left + right << std::endl;
	std::cout << left << " - " << right << " = " << left - right << std::endl;
	std::cout << left << " * " << right << " = " << left * right << std::endl;

	// операциите комплесно + (*) реално число не са дефинирани явно
	// в случая реалното число се преобразува неявно до комплексно,
	// като се използва конструктора на класа ComplexNumber
	std::cout << right << " + " << 5.0 << " = " << right + 5.0 << std::endl;
	std::cout << right << " * " << 5.0 << " = " << right * 5.0 << std::endl;

	std::cout << 5.0 << " + " << right << " = " << 5.0 + right << std::endl;
	std::cout << 5.0 << " * " << right << " = " << 5.0 * right << std::endl;

	std::cout << left << " += " << right << " The result is: ";
	left += right;
	std::cout << left << std::endl;

	std::cout << "Cast " << left << " to double: " << (double)left << std::endl;
	std::cout << "Conjugate " << left << ": " << -left << std::endl;

	std::cout << left << " -= " << right << " The result is: ";
	left -= right;
	std::cout << left << std::endl;

	std::cout << "Prefix ++ over " << left << ": ";
	++left;
	std::cout << left << std::endl;

	return 0;
}