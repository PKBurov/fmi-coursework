#pragma once
#include"File.h"
#include"Date.h"
#include <vector>
using namespace std;

class Folder: public File
{
private:
 
	string FolderName;
	//DateTime date;
	vector<File> files;
	//vecotr<Folder*> folders;
	string Name;
	int Hour;
	int Day;
	int Month;
	int Year;

public:
	//Constructor
	Folder(string name = "-");
	//Getter
	string getFolderName();
	//Setter
	void setName(string NewName);
	//Display time of creation
	void TimeOfCreation() const;
	//Add File
	void addFile(File rhs, string folderName);


};

