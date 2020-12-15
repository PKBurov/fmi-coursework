#include "SmartPhones.h"

#pragma warning(disable: 4996)
SmartPhones& SmartPhones::operator=(const SmartPhones& rhs) {
	if (this != &rhs) {
		Item::operator=(rhs);
		this->color = new char[strlen(rhs.GetColor()) + 1];
		strcpy(this->color, rhs.GetColor());
		this->operative_system = new char[strlen(rhs.GetOperative_Ststem()) + 1];
		strcpy(this->operative_system, rhs.GetOperative_Ststem());
		this->resulution = rhs.Getresulution();
		this->baterry_life = rhs.Getbaterry_life();
		this->weight = rhs.GetWeight();
		this->ram = rhs.GetRam();
	}
	return *this;
}
SmartPhones::SmartPhones(const SmartPhones& rhs) : Item(rhs)
{
	this->color = new char[strlen(rhs.GetColor()) + 1];
	strcpy(this->color, rhs.GetColor());
	this->operative_system = new char[strlen(rhs.GetOperative_Ststem()) + 1];
	strcpy(this->operative_system, rhs.GetOperative_Ststem());
	this->resulution = rhs.Getresulution();
	this->baterry_life = rhs.Getbaterry_life();
	this->weight = rhs.GetWeight();
	this->ram = rhs.GetRam();
}
SmartPhones::SmartPhones()
{
	resulution = 0;
	baterry_life = 0;
	weight = 0;
	ram = 0;
	this->color = new char[1];
	color[0] = '\0';
	this->operative_system = new char[1];
	operative_system[0] = '\0';
}
SmartPhones::~SmartPhones() {

	delete[] color;
	delete[] operative_system;
}
char* SmartPhones::GetColor() const
{
	return this->color;
}
char* SmartPhones::GetOperative_Ststem() const
{
	return this->operative_system;
}
int SmartPhones::Getbaterry_life() const
{
	return this->baterry_life;
}
int SmartPhones::Getresulution() const
{
	return this->resulution;
}
int SmartPhones::GetRam() const
{
	return this->ram;
}
int SmartPhones::GetWeight() const
{
	return this->weight;
}
void SmartPhones::SetColor(const char* Color)
{
	delete[] this->color;
	this->color = new char[strlen(Color) + 1];
	strcpy(this->color, Color);
}
void SmartPhones::SetOperative_System(const char* System)
{
	delete[] this->operative_system;
	this->operative_system = new char[strlen(System) + 1];
	strcpy(this->operative_system, System);
}
void SmartPhones::SetRess(int num) {
	if (num < 0) {
		return;
	}
	this->resulution = num;
}
void SmartPhones::SetBattery(int Num) {
	if (Num < 0) {
		return;
	}
	this->baterry_life = Num;
}
void SmartPhones::SetWeight(int Num) {
	if (Num < 0) {
		return;
	}
	this->weight = Num;
}

void SmartPhones::SetRam(int Num)
{
	if (Num < 0) {
		return;
	}
	this->ram = Num;
}
