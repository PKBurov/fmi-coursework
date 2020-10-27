#include "File.h"
#include <iostream>

#pragma warning(disable : 26812)
using namespace std;
void File::TimeOfCreation()
{
///
}

string File::getName() const
{
	return this->Name;
}

double File::getSize() const
{
	return this->Size;
}
