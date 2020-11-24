#include "IntegerOperation.h"

IntegerOperation::IntegerOperation() {

	operands = new int[1];
	operandCount = 0;
	capacity = 1;
	result = 0;
}

IntegerOperation::IntegerOperation(const IntegerOperation& other) {

	*this = other;
}

const IntegerOperation& IntegerOperation::operator=(const IntegerOperation& other) {

	if (this != &other) {
		copyOperands(other);
		this->capacity = other.capacity;
		this->result = other.result;
		this->operandCount = other.operandCount;
	}

	return *this;
}

IntegerOperation::~IntegerOperation() {

	deleteOperands();
}

void IntegerOperation::copyOperands(const IntegerOperation& src) {

	deleteOperands();
	operands = new int[src.capacity];
	for (int i = 0; i < operandCount; i++) {

		this->operands[i] = src.operands[i];
	}
}

void IntegerOperation::deleteOperands() {
	delete[] operands;
}

void IntegerOperation::insert(const int& operand) {

	if (operandCount == capacity) {
		resize();
	}

	operands[operandCount] = operand;
	operandCount++;
}

void IntegerOperation::resize() {

	int* temp = new int[capacity * 2];

	for (int i = 0; i < operandCount; i++) {
		temp[i] = operands[i];
	}

	capacity *= 2;
	delete[] operands;
	operands = temp;
}

int IntegerOperation::sum() {

	for (int i = 0; i < operandCount; i++) {

		result += operands[i];
	}

	return result;
}

int IntegerOperation::sub() {

	for (int i = 0; i < operandCount; i++) {

		result -= operands[i];
	}

	return result;
}

int IntegerOperation::multiply() {

	for (int i = 0; i < operandCount; i++) {

		result *= operands[i];
	}

	return result;
}

int IntegerOperation::get_result() const {

	return result;
}

int IntegerOperation::operator+(IntegerOperation& rhs){

	return this->sum() + rhs.sum();

}

int IntegerOperation::operator-(IntegerOperation& rhs) {

	return this->sub() - rhs.sub();
}

int IntegerOperation::operator*(IntegerOperation& rhs) {

	return this->multiply() * rhs.multiply();
}