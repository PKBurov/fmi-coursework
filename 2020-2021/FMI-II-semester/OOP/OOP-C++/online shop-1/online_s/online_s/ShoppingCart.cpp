#include "ShoppingCart.h"
#include<iostream>
#include <vector>
#include <cstring>
using namespace std;

void ShoppingCart::addItem(const Item& rhs, const Laptop& laptop) {
	if (rhs.getId()== laptop.getId())
	{
		IT.push_back(rhs);
	}
	else {
		cout << "This Id dosent exist!" << endl;
	}
}

void ShoppingCart::addItem(const Item& rhs, const SmartPhones& smp) {
	if (rhs.getId() == smp.getId())
	{
		IT.push_back(rhs);
	}
	else {
		cout << "This Id dosent exist!" << endl;
	}
}

void ShoppingCart::addItem(const Item& rhs, const Watches& wchs) {
	if (rhs.getId() == wchs.getId())
	{
		IT.push_back(rhs);
	}
	else {
		cout << "This Id dosent exist!" << endl;
	}
}

Item ShoppingCart::searchItem(int ID)
{
	for (int i = 0; i < this->IT.size(); i++) {

		if (this->IT[i].getId() == ID) {
			return this->IT[i];
		}
	}
	return Item();
}

void ShoppingCart::RemoveItem(int id)
{
	int position = -1;
	for (int i = 0; i < this->IT.size(); i++) {
		if (this->IT[i].getId() == id) {
			position = i;
			break;
		}
	}
	if (position == -1) {
		return;
	}
	this->IT.erase(IT.begin()+position);
}


void ShoppingCart::Display(const Item& item, const Laptop& lap)
{
	if (item.getId() != lap.getId())
	{
		cout << "No such item" << endl;
		return;
	}
	for (int i = 0; i < this->IT.size(); i++) {
		cout << " Name: " << IT[i].getName() << " ";
		cout << "| Brand: " << IT[i].getCategory() << " ";
		cout << "| Price: " << IT[i].getPrice() << " lv ";
		cout << "| Quantity:  " << IT[i].getQuantity() << " ";
		cout << "| Item ID: " << IT[i].getId() << endl;
	}
}
void ShoppingCart::Display(const Item& item, const SmartPhones& smp)
{
	if (item.getId() != smp.getId())
	{
		cout << "No such item" << endl;
		return;
	}
	for (int i = 0; i < this->IT.size(); i++) {
		cout << " Name: " << IT[i].getName() << " ";
		cout << "| Brand: " << IT[i].getCategory() << " ";
		cout << "| Price: " << IT[i].getPrice() << " lv ";
		cout << "| Quantity:  " << IT[i].getQuantity() << " ";
		cout << "| Item ID: " << IT[i].getId() << endl;
	}
}
void ShoppingCart::Display(const Item& item, const Watches& wch)
{
	if (item.getId() != wch.getId())
	{
		cout << "No such item" << endl;
		return;
	}
	for (int i = 0; i < this->IT.size(); i++) {
		cout << " Name: " << IT[i].getName() << " ";
		cout << "| Brand: " << IT[i].getCategory() << " ";
		cout << "| Price: " << IT[i].getPrice() << " lv ";
		cout << "| Quantity:  " << IT[i].getQuantity() << " ";
		cout << "| Item ID: " << IT[i].getId() << endl;
	}
}
