#include "Laptop.h"
#include <string>
using namespace std;
#pragma warning(disable: 4996)
Laptop& Laptop::operator=(const Laptop& rhs) {
	if (this != &rhs) {
		Item::operator=(rhs);
		this->procesor.erase();
		this->procesor = rhs.getProcesor();
		this->resulution = rhs.Getresulution();
		this->baterry_life = rhs.Getbaterry_life();
	}
	return *this;
}
Laptop::Laptop(const Laptop& rhs) : Item(rhs)
{
	this->procesor = rhs.getProcesor();
	this->resulution = rhs.Getresulution();
	this->baterry_life = rhs.Getbaterry_life();
}

string Laptop::getProcesor() const
{
	return this->procesor;
}

int Laptop::Getbaterry_life() const
{
	return this->baterry_life;
}

int Laptop::Getresulution() const
{
	return this->resulution;
}

void Laptop::SetProcesor(string procesor)
{
	this->procesor.erase();
	this->procesor = procesor;
}

void Laptop::setRess(int num){
	if (num<0){
		return;
	}
	this->resulution = num;
}

void Laptop::setBattery(int Num){
	if (Num < 0) {
		return;
	}
	this->baterry_life = Num;
}
