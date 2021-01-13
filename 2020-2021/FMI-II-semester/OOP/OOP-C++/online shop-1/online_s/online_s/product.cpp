#include "product.h"
#pragma warning(disable: 4996)
#include <iostream>
int StrLen(const char* Str)//strlen
{
	int Counter = 0;
	while (Str[Counter] != '\0')
	{
		Counter++;
	}
	return Counter;
}
Item::Item(){
	this->category = new char[1];
	this->category[0] = '\0';
	this->name = new char[1];
	this->name[0] = '\0';
	this->price = 0;
	this->quantity = 0;
	this->id = 0;
}
Item::Item(const char* nm, double pr, int qty, const char* category, int Id) {
	this->name = new char[strlen(nm) + 1];
	strcpy(this->name, nm);
	this->category = new char[strlen(category) + 1];
	strcpy(this->category, category);
	this->price = pr;
	this->quantity = qty;
	this->id = Id;
}
Item::~Item() {
	delete[] name;
	delete[] category;
}
Item& Item::operator=(const Item& rhs) {
	if (this != &rhs) {

		this->name = new char[strlen(rhs.getName()) + 1];
		strcpy(this->name, rhs.getName());
		this->category = new char[strlen(rhs.getCategory()) + 1];
		strcpy(this->category,rhs.getCategory());
		this->price = rhs.getPrice();
		this->quantity = rhs.getQuantity();
		this->id = rhs.getId();
	}
	return *this;
}

Item::Item(const Item& rhs) {
	this->name = new char[strlen(rhs.getName()) + 1];
	strcpy(this->name, rhs.getName());
	this->category = new char[strlen(rhs.getCategory()) + 1];
	strcpy(this->category, rhs.getCategory());
	this->price = rhs.price;
	this->quantity = rhs.getQuantity();
	this->id = rhs.getId();
}

int Item::getId() const {
	return this->id;
}
void Item::setName(const char* nm)
{
	delete[] this->name;
	this->name = new char[strlen(nm) + 1];
	strcpy(this->name, nm);
}
void Item::setID(int num)
{
	this->id = num;
}
char* Item::getName() const
{
	return this->name;
}

void Item::setPrice(double pr)
{
	price = pr;
}
double Item::getPrice() const
{
	return price;
}

void Item::setQuantity(int qty)
{
	quantity = qty;
}
int Item::getQuantity() const
{
	return quantity;
}

void Item::setCategory(const char* ctg) {
	delete[] category;
	this->category = new char[StrLen(ctg) + 1];
	strcpy(this->category, ctg);
}
char* Item::getCategory()const {
	return this->category;
}