#include "Header.h"
//Конструктор по подразбиране
IntegerOperation::IntegerOperation() {

	operands = new int[1];
	operandCount = 0;
	capacity = 1;
	result = 0;
}
/* Копи конструктор връща връща *this=other, защото е подаден по референция, един вид имам целия обект  
	и дефинирам this пойтера да получиш обекта към който сочи и се получава обект1=обект2;
	иначе, щеше да е указател = на обект което щеше да гръмне
*/
IntegerOperation::IntegerOperation(const IntegerOperation& other) {

	*this = other;
}

const IntegerOperation& IntegerOperation::operator=(const IntegerOperation& other) {

	if (this != &other) //проверка да не присвой себе си
	{
		/*Copy Operands е helper function да копира операндите от един масив в друг
		*/
		copyOperands(other);
		this->capacity = other.capacity;
		this->result = other.result;
		this->operandCount = other.operandCount;
	}

	return *this;
}
// Деструктор
IntegerOperation::~IntegerOperation() {
	deleteOperands();
}
//защото е казано в условието, че човек може да вкарва неизвестен брой числа
void IntegerOperation::copyOperands(const IntegerOperation& src) {

	deleteOperands();
	operands = new int[src.capacity];
	for (int i = 0; i < operandCount; i++) {
		//копират се от един масив в друг
		this->operands[i] = src.operands[i];
	}
}

//Функция която извиква деструктура.
void IntegerOperation::deleteOperands() {
	delete[] operands;
}
// Тъй като потребителя може да добавя числа върху които да будат извършени различен брой операции;
// Функцията за добавяне.
void IntegerOperation::insert(const int& operand) {

	if (operandCount == capacity) {
		resize();
	}
	operands[operandCount] = operand;
	operandCount++;
}

void IntegerOperation::resize() {
	/*Тъй като не знаем колко пъти потребителя ще добавя нови числа, трябва да направим rezaizable array, като 
		заделяме нов динамичен масив който е с двойна големина на capacity'to, прехвърлят се всички стойности от единият масив
		в другият, задава се ново capacity, ако потребителят реши да добавя още, числа масива да може да се разшири, трие старият масив
		и се присвоява темп на operands
	*/
	int* temp = new int[capacity * 2];
	for (int i = 0; i < operandCount; i++) {
		temp[i] = operands[i];
	}
	capacity *= 2;
	delete[] operands;
	operands = temp;
}

int IntegerOperation::sum() {
	//OperandCount, колкото пъти имаме добавено число
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

//Извършва операция събиране върху двата обекта и след това връща сбора от резултатите им 
int IntegerOperation::operator+(IntegerOperation& rhs) {
	return this->sum() + rhs.sum();
}
//Извършва операция изваждане върху двата обекта и след това връща произведението от резултатите им
int IntegerOperation::operator-(IntegerOperation& rhs) {

	return this->sub() - rhs.sub();
}
//Извършва операция умножение върху двата обекта и след това връща произведението от резултатите им
int IntegerOperation::operator*(IntegerOperation& rhs) {

	return this->multiply() * rhs.multiply();
}