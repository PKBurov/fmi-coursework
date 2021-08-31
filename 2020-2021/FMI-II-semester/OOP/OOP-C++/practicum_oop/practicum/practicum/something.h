#pragma once

#include<iostream>
class Complex
{
private:
	double real, imag;

public:
	
	Complex() {
		real = imag = 0;
	}
	Complex(Complex& obj) {
		real = obj.real;
		imag = obj.imag;
	}
	Complex(double r) {
		real = r;
		imag = 0;
	}
	Complex(double r, double i) {
		real = r;
		imag = i;
	}
	Complex add(Complex c) {
		Complex Add;
		Add.real = real + c.real;
		Add.imag = imag + c.imag;
		return Add;
	}
	Complex sub(Complex c) {
		Complex Sub;
		Sub.real = real - c.real;
		Sub.imag = imag - c.imag;
		return Sub;
	}
	Complex mult(Complex c) {
		Complex Mult;
		Mult.real = real * c.real - imag * c.imag;
		Mult.imag = real * c.imag - c.real * imag;
		return Mult;
	}


	void print() {
		std::cout << real << "+" << imag << "i" << std::endl << std::endl;
	}
	double getReal() const {
		return real;
	}
	double getImag() const {
		return imag;
	}
	void setReal(double re) {
		real = re;
	}
	void setImag(double im) {
		imag = im;
	}

};

