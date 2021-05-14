#pragma once
#include<iostream>
class MyString {
private:
	char* content;
public:
	MyString();
	MyString(const char* input);

	MyString(const MyString& from);

	MyString& operator=(const MyString& from);

	//Operators
	friend std::ostream& operator<< (std::ostream& so, const MyString& s);
	friend std::istream& operator>> (std::istream& so, MyString& s);

	~MyString();

	void append(char to_append);
	void print();
};