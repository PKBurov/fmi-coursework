#include <iostream>

#include "Set.h"

Set::Set(size_t capacity)
	:capacity(capacity), count(0)
{
	this->elements = new int[this->capacity];
}

// копиращ конструктор
Set::Set(const Set& right)
{
	copy(right);
}

Set& Set::operator=(const Set& right)
{
	if(this != &right)
	{
		delete[] this->elements;
		copy(right);
	}

	return *this;
}

Set::~Set()
{
	delete[] this->elements;
}

void Set::copy(const Set& right)
{
	this->capacity = right.capacity;
	this->count = right.count;

	this->elements = new int[this->capacity];
	for(size_t i = 0; i < this->count; ++i)
	{
		this->elements[i] = right.elements[i];
	}
}

// оператор за индексиране
int& Set::operator[](size_t index)
{
	if(index >= this->count)
		throw "Index out of bounds!";

	return this->elements[index];
}
// константна версия на оператора
const int& Set::operator[](size_t index) const
{
	if(index >= this->count)
		throw "Index out of bounds!";

	return this->elements[index];
}

// operator(), с аргумент цяло число
// проверява дали елементът принадлежи на множеството
bool Set::operator()(int elem) const
{
	size_t i = 0;
	while(i < this->count && this->elements[i] != elem)
	{
		++i;
	}

	return i < this->count;
}

// проверява дали множеството не е празно
bool Set::operator!() const
{
	return this->count == 0;
}

void Set::resize()
{
	this->capacity = (this->capacity == 0) ? 1 : 2 * this->capacity;

	int* buffer = new int[this->capacity];
	for(size_t i = 0; i < this->count; ++i)
	{
		buffer[i] = this->elements[i];
	}

	delete[] this->elements;
	this->elements = buffer;
}

// добавя елемент към множеството
Set& Set::operator+=(int newElem)
{
	// ако елементът вече е в множеството
	if((*this)(newElem))
		return *this;

	// дали има място за новия елемент?
	if(this->count >= this->capacity)
	{
		this->resize();
	}

	this->elements[this->count] = newElem;
	++this->count;
}
// обединение на множества
Set& Set::operator+=(const Set& right)
{
	for(size_t i = 0; i < right.count; ++i)
	{
		*this += right.elements[i];
	}

	return *this;
}

// премахва елемент от множеството
Set& Set::operator-=(int elem)
{
	// елементът не принадлежи на множеството
	//if(!(*this)(elem))
	//	return *this;

	size_t i = 0;
	while(i < this->count && this->elements[i] != elem)
	{
		++i;
	}

	// елементът е намерен на позиция i
	if(i < this->count)
	{
		// премахваме елемента
		this->elements[i] = this->elements[this->count - 1];
		--this->count;
	}

	return *this;
}
// разлика на две множества
Set& Set::operator-=(const Set& right)
{
	for(size_t i = 0; i < right.count; ++i)
	{
		*this -= right.elements[i];
	}

	return *this;
}

// сечение на две множества
Set& Set::operator*=(const Set& right)
{
	for(size_t i = 0; i < this->count; ++i)
	{
		// ако елементът не принадлежи на дясното множество
		if(!right(this->elements[i]))
		{
			// премахваме го
			*this -= this->elements[i];
			// стъпка назад, за да се разгледа новия елемент на тази позиция
			--i;
		}
	}

	for(size_t i = 0; i < right.count; ++i)
	{
		// ако елементът не принадлежи на текущото множество
		if(!(*this)(right.elements[i]))
		{
			// премахваме го
			*this -= right.elements[i];
		}
	}

	return *this;
}

// сравнение на две множества
bool operator==(const Set& left, const Set& right)
{
	if(left.getElementsCount() != right.getElementsCount())
		return false;

	for(size_t i = 0; i < left.getElementsCount(); ++i)
	{
		if(left[i] != right[i])
			return false;
	}

	return true;
}

bool operator!=(const Set& left, const Set& right)
{
	return !(left == right);
}

// подмножество
bool operator<(const Set& left, const Set& right)
{
	if(left.getElementsCount() >= right.getElementsCount())
		return false;

	for(size_t i = 0; i < left.getElementsCount(); ++i)
	{
		if(right(left[i]))
			return false;
	}

	return true;
}

Set operator+(const Set& left, int right)
{
	Set result = left;
	result += right;

	return result;
}

Set operator+(const Set& left, const Set& right)
{
	Set result = left;
	for(size_t i = 0; i < right.getElementsCount(); ++i)
	{
		result += right[i];
	}

	return result;
}

Set operator-(const Set& left, int right)
{
	Set result = left;
	result -= right;

	return result;
}

Set operator-(const Set& left, const Set& right)
{
	Set result = left;
	for(size_t i = 0; i < right.getElementsCount(); ++i)
	{
		result -= right[i];
	}

	return result;
}

Set operator*(const Set& left, const Set& right)
{
	Set result = left;
	result *= right;

	return result;
}

std::ostream& operator<< (std::ostream& out, const Set& set)
{
	out << "{ ";
	for(size_t i = 0; i < set.getElementsCount(); i++)
	{
		out << set[i] << " ";
	}

	out << "}";

	return out;
}