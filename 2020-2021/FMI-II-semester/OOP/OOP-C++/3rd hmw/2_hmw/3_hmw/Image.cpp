#include "Image.h"

Image::Image(string device, int Width, int Height, Extensions extension, string name, double size)
{
	device = "SmartPhone";
	Width = 640;
	Height = 480;
	extension = jpg;
	name = "Cat and Dogs";
	size = 4.0;
}

string Image::getDevice() const
{
	return this->device;
}

int Image::getPictureWidth() const
{
	return this->Width;
}

int Image::getPictureHeight() const
{
	return this->Height;
}

void Image::viewExtension() const
{

}
