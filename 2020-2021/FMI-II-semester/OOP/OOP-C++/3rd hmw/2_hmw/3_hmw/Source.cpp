#include<iostream>
#include<string>
#include<fstream>
#include"Image.h"
#include"Folder.h"
#include"File.h"
#include"MusicalFile.h"

int main() {

	File f;
	Image ImageFile{ "Camera", 640, 480, jpg, "Cat picture", 2.5 };
	cout << "Image File" << endl;
	cout << "This image was taken by: " << ImageFile.getDevice() << endl;
	cout << "File name:" << ImageFile.getName() << endl;
	cout << "Resolution Width" << ImageFile.getPictureWidth() << endl;
	cout << "Resolution Height" << ImageFile.getPictureHeight() << endl;
	cout << "File size in MB" << ImageFile.getSize()<<endl;
	cout << "Date and time of creation"; ImageFile.TimeOfCreation();
	cout << "File extension"; ImageFile.viewExtension();
	cout << "...................." << endl;

	MusicalFile Song{"Daniel Caesar","Best Part",2018, flac , 4};
	cout << "Music File" << endl;
	cout << "...................." << endl;
	cout << "Artist: " << Song.getArtist() << endl;
	cout << "Song:" << Song.getSong() << endl;
	cout << "Year of release" << Song.getReleaseYear() << endl;
	cout << "File name:" << Song.getName() << endl;
	cout << "File size in MB" << Song.getSize();
	cout << "Date and time of creation"; Song.TimeOfCreation();
	cout << "File extension"; Song.viewExtension();
	cout << "...................." << endl;

	//string FileName;
	//ofstream FileC;

	//string Name;


	//int choice = 0;
	//cout << "File System Menu" << endl;
	//cout << "\t" << "What kind of file do you want to make?" << endl;
	//cout << "1. Image File" << endl;
	//cout << "2. Music File" << endl;
	//cout << "Enter choice";
	//cin >> choice;
	//switch (choice){
	//case 1:
	//	cout << "Name of file: "; 
	//	cin >> Name;

	//	break;
	//case 2:


	//	break;


	//default:
	//	break;
	//}




	std::cin.get();
}