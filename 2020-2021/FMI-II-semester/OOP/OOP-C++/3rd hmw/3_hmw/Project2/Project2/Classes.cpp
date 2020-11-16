#include "Classes.h"

string Classes::getClassName() const
{
	return this->ClassName;
}

string Classes::getClassType() const
{
	return this->ClassType;
}

int Classes::getClassCode() const
{
	return this->ClassCode;
}

string Classes::getTeacher() const
{
	return this->Teacher;
}

int Classes::getStudents() const
{
	return this->EnrolledStudents;
}
