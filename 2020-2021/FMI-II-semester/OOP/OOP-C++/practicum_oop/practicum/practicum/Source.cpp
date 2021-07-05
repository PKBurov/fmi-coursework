#include<iostream>
#include"something.h"

using namespace std;

int main()
{
	double real1, imag1, real2, imag2;

	cout << "Enter the Real  part of First Number: ";
	cin >> real1;
	cout << "Enter the imaginary  part of First Number: ";
	cin >> imag1;
	Complex obj1(real1, imag1);
	obj1.print();

	cout << "Enter the Real part of Second Number: ";
	cin >> real2;
	cout << "Enter the Imaginary part of second number: ";
	cin >> imag2;
	Complex obj2(real2, imag2);
	obj2.print();

	Complex c;
	c = obj1.add(obj2);
	cout << "Addition is : (" << c.getReal() << ")+(" << c.getImag() << ")i" << endl;
	c = obj1.sub(obj2);
	cout << endl << "Subtraction is : (" << c.getReal() << ")+(" << c.getImag() << ")i" << endl;

	c = obj1.mult(obj2);
	cout << endl << "Multiplication is : (" << c.getReal() << ")+(" << c.getImag() << ")i" << endl;

	return 0;
}