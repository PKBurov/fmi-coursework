#include "Mystring.h"
#include <cstring>
#include <iostream>

//Constructors:
Mystring::Mystring(const char* string)
{
	m_Size = strlen(string);
	m_Buffer = new char[m_Size + 1];
	memcpy(m_Buffer, string, m_Size);
	m_Buffer[m_Size] = 0;
}
Mystring::Mystring(const Mystring& other)
	:m_Size(other.m_Size)
{
	m_Buffer = new char[m_Size + 1];
	memcpy(m_Buffer, other.m_Buffer, m_Size+1);
}

//Destructors:
Mystring::~Mystring()
{
	delete[] m_Buffer;
}

//Operators:
std::ostream& operator<<(std::ostream& stream, const Mystring& string)
{
	stream << string.m_Buffer;
	return stream;
}
//==
bool operator==(const Mystring& lhs, const Mystring& rhs)
{
	unsigned counter = 0;
	if (lhs.m_Size != rhs.m_Size)
		return false;
	else{
		for (unsigned i = 0; i < lhs.m_Size; i++){
			if (lhs.m_Buffer[i] != rhs.m_Buffer[i]) counter++;
		}
	}
	if (counter == 0)
		return true;
}
// !=
bool operator!=(const Mystring& lhs, const Mystring& rhs)
{
	unsigned counter = 0;
	if (lhs.m_Size != rhs.m_Size){
		return true;
	}else{
		for (unsigned i = 0; i < lhs.m_Size; i++) {
			if (lhs.m_Buffer[i] != rhs.m_Buffer[i]) counter++;
		}
	}if (counter == 0)
		return false;
}
// <
bool operator<(const Mystring& lhs, const Mystring& rhs)
{
	if (lhs.m_Size < rhs.m_Size){
		return true;
	}else if (lhs.m_Size > rhs.m_Size){
		return false;
	}
	exit(1);
}
// >
bool operator>(const Mystring& lhs, const Mystring& rhs)
{
	if (lhs.m_Size > rhs.m_Size){
		return true;
	}else if (lhs.m_Size < rhs.m_Size){
		return false;
	}
	exit(1);
}
// Methods
void Mystring::Append(const Mystring& other, const char* string)
{
	std::cout << other << string << std::endl;
}
void Mystring::PrintString(const Mystring& Mystring)
{
	std::cout << Mystring << std::endl;
}
