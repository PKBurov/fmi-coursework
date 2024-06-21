#include <iostream>

#include "ComplexNumber.h"

int main()
{
	ComplexNumber cn;
	read(cn);
	std::cout << "First complex number: ";
	print(cn);

	ComplexNumber two = { 2, 0 };
	std::cout << "Second complex number: ";
	print(two);

	std::cout << "Equal: " << std::boolalpha << equal(cn, two) << std::endl;
	
	std::cout << "Sum of two complex numbers:" << std::endl;
	ComplexNumber sumOfTwoComplex = sum(cn, two);
	print(sumOfTwoComplex);

	std::cout << "Substract two complex numbers:" << std::endl;
	ComplexNumber diffOfTwoComplex = substract(cn, two);
	print(diffOfTwoComplex);

	std::cout << "Product of two complex numbers:" << std::endl;
	ComplexNumber prodOfTwoComplex = product(cn, two);
	print(prodOfTwoComplex);

	std::cout << "Conjugate the complexnumber ";
	print(cn);

	ComplexNumber conjComplex = conjugate(cn);
	print(conjComplex);

	return 0;
}