#pragma once
#include<string>
using namespace std;
enum Titles{
	part_time_lecturer,
	Chief_Assistant,
	Doctor,
	Associate_Professor,
	Professor,
	none_t
};
enum Classes{ Pure_Mathematics, Physics, Astronomy, none};

class Teacher
{
private:
	string Name;
	Titles Title;
	Classes Class;

public:
	Teacher(string Name, Titles Title , Classes Class)
		:Name("-"), Title(none_t), Class(none) {}
	string getName() const;
	int getTitles()const;
	int getClasses() const;

};

