#include "Watches.h"
#pragma warning(disable: 4996)
Watches& Watches::operator=(const Watches& rhs) {
	if (this != &rhs) {
		Item::operator=(rhs);
		this->WatchMaterial.erase();
		this->WatchMaterial = rhs.GetWatchMaterial();
		//
		this->WatchGlass.erase();
		this->WatchGlass = rhs.GetWatchGlass();
		//
		this->WatchMovement.erase();
		this->WatchMovement = rhs.GetWatchMovement();
		//
		this->WatchWaterRess .erase();
		this->WatchWaterRess = rhs.GetWatchWaterRess();
	}
	return *this;
}
Watches::Watches(const Watches& rhs) : Item(rhs)
{
	this->WatchMaterial.erase();
	this->WatchMaterial = rhs.GetWatchMaterial();
	//
	this->WatchGlass.erase();
	this->WatchGlass = rhs.GetWatchGlass();
	//
	this->WatchMovement.erase();
	this->WatchMovement = rhs.GetWatchMovement();
	//
	this->WatchWaterRess.erase();
	this->WatchWaterRess = rhs.GetWatchWaterRess();
}

string Watches::GetWatchMaterial() const
{

	return this->WatchMaterial;
}

string Watches::GetWatchGlass() const
{
	return this->WatchGlass;
}

string Watches::GetWatchMovement() const
{
	return this->WatchMovement;
}

string Watches::GetWatchWaterRess() const
{
	return this->WatchWaterRess;
}

void Watches::SetWatchMaterial(string Material)
{

	this->WatchMaterial.erase();
	this->WatchMaterial = Material;
}

void Watches::SetWatchGlass(string Glass)
{
	this->WatchGlass.erase();
	this->WatchGlass = Glass;
}

void Watches::SetWatchMovement(string Movement)
{
	this->WatchMovement.erase();
	this->WatchMovement = Movement;
}

void Watches::SetWatchWaterRess(string Ress)
{
	this->WatchWaterRess.erase();
	this->WatchWaterRess = Ress;
}
