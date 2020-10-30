#pragma once
#pragma warning(disable : 26812)
#include<string>
#include <iomanip>
#include <ctime>
#include <stdlib.h> 
using namespace std;

enum Extensions{jpg,png,mp3,flac,no_ext};

class File
{
protected:
	string Name;
	double Size =0;
	Extensions extension;
	/*int Hour;
	int Day;
	int Month;
	int Year;*/
public:
	//Constructor
	//File(string name = "-", double size = 0);
	//Date-Time
	void TimeOfCreation();
	//Getter
	string getName() const;
	double getSize() const;
	//Display
	virtual void viewExtension()const {};
	
};

