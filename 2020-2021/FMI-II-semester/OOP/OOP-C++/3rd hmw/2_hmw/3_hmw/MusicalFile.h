#pragma once
#pragma warning(disable : 26812)
#include"File.h"

using namespace std;
class MusicalFile : public File
{
private:
	string Artist;
	string Song;
	int releaseYear = 0;
	//Helper
	bool ValidExtension(Extensions newExtension) const;
public:
	//constructor
	MusicalFile(string Artist = "-" , string Song= "-", int releaseYear = 0, Extensions = no_ext , double size = 0);
	//Setters
	void setExtensions(Extensions newExtension);
	//Getters
	string getArtist() const;
	string getSong() const;
	int getReleaseYear() const;
	//View Extension
	void viewExtension() const;
};

