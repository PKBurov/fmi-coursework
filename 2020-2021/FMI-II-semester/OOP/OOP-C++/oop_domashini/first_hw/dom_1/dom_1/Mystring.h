#pragma once
#include<iostream>
class Mystring{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	//Constructor:
	Mystring(const char* string);
	Mystring(const Mystring& other);
	//Destructor:
	~Mystring();
	//Operators:
	friend std::ostream& operator<<(std::ostream& stream, const Mystring& string);
	// ==
	friend bool operator==(const Mystring& lhs, const Mystring& rhs);
	// !=
	friend bool operator!=(const Mystring& lhs, const Mystring& rhs);
	// <
	friend bool operator<(const Mystring& lhs, const Mystring& rhs);
	// >
	friend bool operator>(const Mystring& lhs, const Mystring& rhs);
	//Methods:
	void Append(const Mystring& other, const char* string);
	void PrintString(const Mystring& Mystring);
};

