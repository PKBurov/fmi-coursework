#include "MusicalFile.h"

bool MusicalFile::ValidExtension(Extensions newExtension) const
{
	if (newExtension != jpg && newExtension != png
		&& newExtension != mp3 && newExtension != flac){

	return false;
	}
	return true;
}

MusicalFile::MusicalFile(string Artist, string Song, int releaseYear, Extensions Extension, double size)
{
	Artist = "Someone";
	Song = "Something";
	Extension = no_ext;
	releaseYear = 2018;
	size = 4;
}

void MusicalFile::setExtensions(Extensions newExtension)
{
	if (ValidExtension(newExtension) == true){
		this->extension = newExtension;
	}
}

string MusicalFile::getArtist() const
{
	return this->Artist;
}

string MusicalFile::getSong() const
{
	return this->Song;
}

int MusicalFile::getReleaseYear() const
{
	return this->releaseYear;
}

void MusicalFile::viewExtension() const
{
}
