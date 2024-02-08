#include <iostream>

#include "ComplexNumber.h"

int main()
{
	ComplexNumber zero;
	std::cout << "Using default constructor: ";
	zero.print();

	ComplexNumber two(2, 3);
	std::cout << "Second complex number: ";
	two.print();

	std::cout << "Equal: " << std::boolalpha << zero.equals(two) << std::endl;
	
	std::cout << "Sum of two complex numbers:" << std::endl;
	ComplexNumber sumOfTwoComplex = zero.add(two);
	sumOfTwoComplex.print();

	std::cout << "Substract two complex numbers:" << std::endl;
	ComplexNumber diffOfTwoComplex = zero.substract(two);
	diffOfTwoComplex.print();

	std::cout << "Product of two complex numbers:" << std::endl;
	ComplexNumber prodOfTwoComplex = zero.multiply(two);
	prodOfTwoComplex.print();

	std::cout << "Conjugate the complex number ";
	two.print();

	ComplexNumber conjComplex = two.conjugate();
	conjComplex.print();

	return 0;
}