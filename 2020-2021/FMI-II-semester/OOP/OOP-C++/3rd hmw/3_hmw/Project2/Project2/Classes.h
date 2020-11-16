#pragma once
#include<string>
using namespace std;
class Classes
{
private:
	string ClassName;
	string ClassType;
	int ClassCode;
	string Teacher;
	int EnrolledStudents;
public:
	Classes(const string ClassName, const string ClassType, const int ClassCode, const string Teacher, const int EnrolledStudents)
		:ClassName("-"), ClassType("-"), ClassCode(0), Teacher("-"), EnrolledStudents(0) {}
	//Getters
	string getClassName() const;
	string getClassType() const;
	int getClassCode() const;
	string getTeacher() const;
	int getStudents() const;

};

