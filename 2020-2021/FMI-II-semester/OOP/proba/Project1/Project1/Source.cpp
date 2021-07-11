#include<iostream>
#include<fstream>
#include<string>


template<class T>
class Printer {
private:
	std::ostream* outStream;
public:
	Printer(std::ostream& outputStream) {
		this->outStream = &outputStream;
	}
	void print(T data) {
		*(this->outStream) << data;
	}
};

int main() {
	Printer<int>printer1(std::cout);
	printer1.print(123);

	std::ofstream outStream("f.out");
	Printer<std::string> printer2(outStream);
	printer2.print("This is a very ");
	printer2.print("important setence");

	Printer<std::string> printer3(std::cout);
	printer3.print("you've got mail");

	outStream.close();
	printer2.print("This is another sentence");




}