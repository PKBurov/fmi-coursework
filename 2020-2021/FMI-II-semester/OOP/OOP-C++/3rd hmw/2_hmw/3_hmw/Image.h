#pragma once


#include<iostream>
#include<string>
#include"File.h"
using namespace std;


class Image : public File
{
private:

	string device;
	int Width=0;
	int Height=0;

	//bool ValidExt(Extensions newExtension);
public:

	//Constructor;
	Image(string device = "-", int Width= 0, int Height = 0, Extensions extension = no_ext, string name = "-" , double size = 0);
	// Getters
	string getDevice() const;
	int getPictureWidth() const;
	int getPictureHeight() const;
	//View extension
	void viewExtension()const;

};

