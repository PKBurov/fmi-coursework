#include "Rectangle.h"
#include <cstring>
#include <iostream>
#include<cmath>
Shape::Shape() {
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
	diagonal = 0;
	area = 0;
	length = 0;
	width = 0;
}
Shape::Shape(const Shape& CopyFrom) {
	x1 = CopyFrom.x1;
	y1 = CopyFrom.y1;
	x2 = CopyFrom.x2;
	y2 = CopyFrom.y2;
	diagonal = CopyFrom.diagonal;
	area = CopyFrom.area;
	length = CopyFrom.length;
	width = CopyFrom.width;
}
Shape& Shape::operator=(const Shape& other) {
	if (this != &other) {
		x1 = other.x1;
		y1 = other.y1;
		x2 = other.x2;
		y2 = other.y2;
		diagonal = other.diagonal;
		area = other.area;
		length = other.length;
		width = other.width;
	}
	return *this;
}
void Shape::setDiagonal(double width, double length) {
	diagonal = (sqrt(width * width + length * length));
}
void Shape::setArea(int length, int width) {
	area = (width * length);
}
void Shape::setLength(double x1, double x2) {
	if (x1 > x2) {
		length = x1 - x2;
	}
	else {
		length = x2 - x1;
	}
}
void Shape::setWidth(double y1, double y2) {
	if (y1 > y2) {
		width = y1 - y2;
	}
	else {
		width = y2 - y1;
	}
}
void Shape::setX1(double newX1) {
	x1 = newX1;
}
void Shape::setX2(double newX2) {
	x2 = newX2;
}
void Shape::setY1(double newY1) {
	y1 = newY1;
}
void Shape::setY2(double newY2) {
	y2 = newY2;
}

const double Shape::getDiagonal() const {
	return diagonal;
}
const double Shape::getArea() const {
	return area;
}
const double Shape::getLength() const {
	return length;
}
const double Shape::getWidth() const {
	return width;
}
const double Shape::getX1() const {
	return x1;
}
const double Shape::getX2() const {
	return x2;
}
const double Shape::getY1() const {
	return y1;
}
const double Shape::getY2() const {
	return y2;
}
void Shape::Create() {
	std::cout << "x1:" << std::endl;
	std::cin >> x1;
	std::cout << "y1: " << std::endl;
	std::cin >> y1;
	std::cout << "x2: " << std::endl;
	std::cin >> x2;
	std::cout << "y2: " << std::endl;
	std::cin >> y2;
	setLength(x1, x2);
	setWidth(y1, y2);
	setDiagonal(width, length);
	setArea(length, width);
}