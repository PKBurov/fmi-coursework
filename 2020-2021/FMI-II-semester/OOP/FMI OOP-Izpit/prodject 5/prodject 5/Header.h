#pragma once
class IntegerOperation
{
private:
	int operandCount;
	int* operands;
	int result;
	int capacity;
	void copyOperands(const IntegerOperation& src);
	void deleteOperands();
	void resize();

public:
	IntegerOperation();
	IntegerOperation(const IntegerOperation& other);
	const IntegerOperation& operator=(const IntegerOperation& other);
	~IntegerOperation();

	void insert(const int& operand);
	int get_result() const;

	int sum();
	int sub();
	int multiply();

	int operator +(IntegerOperation& rhs);
	int operator -(IntegerOperation& rhs);
	int operator *(IntegerOperation& rhs);
};

