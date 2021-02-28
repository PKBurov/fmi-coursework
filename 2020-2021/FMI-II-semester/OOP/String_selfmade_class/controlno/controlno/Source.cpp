#include<iostream>
#include<string.h>
#pragma warning(disable: 4996)
using namespace std;

class String
{
	char* str;
public:
	String(const char* s);
	void change(int index, char c) { str[index] = c; }
	char* get() { return str; }
	String boss;
};

String::String(const char* s) {
	int l = strlen(s);
	str = new char[l + 1];
	strcpy(str, s);
}

int main() {
	String s1("myTest");
	String s2 = s1;
	s1.change(0, 'M');
	cout << s1.get() << " ";
	cout << s2.get();
}