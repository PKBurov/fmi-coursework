#pragma once
#include<string>
using namespace std;
class Student
{
private:
	string Name;
	int fn;
	int EnrolledClasses;
	int Marks;

public:
	Student(string Name, int fn, int EnrolledClasses, int Marks)
		:Name("-"), fn(0), EnrolledClasses(0), Marks(0){}
	int getFn()const;
	int getEnrollClasses() const;
	int getMarks() const;

};

