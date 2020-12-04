#include "Inventory.h"
#include <iostream>
#include <vector>
using namespace std;
//
//void Inventory::addItem(const Item& item) {
//	int NewArrEnd = this->arrayEnd + 1;
//	Item* theNew = new Item[NewArrEnd];
//	theNew[this->arrayEnd] = item;
//	for (int i = 0; i < this->arrayEnd; i++) {
//		theNew[i] = this->items[i];
//	}
//	delete[] this->items;
//	this->items = theNew;
//	this->arrayEnd++;
//}
//Inventory::~Inventory(){
//	delete[] this->items;
//}
//Item Inventory::search(int id) {
//	for (int i = 0; i < this->arrayEnd; i++) {
//
//		if (this->items[i].getId() == id) {
//			return this->items[i];
//		}
//	}
//	return Item();
//}
//void Inventory::RemoveItem(int idx) {
//	
//	Item* theNew = new Item[this->arrayEnd - 1];
//	for (int i = 0; i < idx; i++) {
//		theNew[i] = this->items[i];
//	}
//	for (int i = idx + 1; i < this->arrayEnd; i++) {
//		theNew[i - 1] = this->items[i];
//	}
//	delete[] items;
//	this->items = theNew;
//	this->arrayEnd--;
//}
//void Inventory::Display() {
//	for (int i = 0; i < this->arrayEnd; i++) {
//		cout << "Item: " << this->items[i].getName() << "| From category : " << this->items[i].getCategory() << "| With ID " << this->items[i].getId() << endl;
//	}
//}
//Laptop
void Inventory::addLaptop(const Laptop& item) {
	laptop.push_back(item);
}
Laptop Inventory::searchLaptop(int id) {
	for (int i = 0; i < this->laptop.size(); i++) {

		if (this->laptop[i].getId() == id) {
			return this->laptop[i];
		}
	}
	return Laptop();
}
void Inventory::removeLaptop(int id) {
	int position = -1;
	for (int i = 0; i < this->laptop.size(); i++) {
		if (this->laptop[i].getId() == id) {
			position = i;
			break;
		}
	}
	if (position == -1) {
		return;
	}
	this->laptop.erase(laptop.begin() + position);

}
//SmartPhone
void Inventory::addSmartPhone(const SmartPhones& rhs)
{
	smartp.push_back(rhs);
}
SmartPhones Inventory::searchSmartp(int id)
{
	for (int i = 0; i < this->smartp.size(); i++) {

		if (this->smartp[i].getId() == id) {
			return this->smartp[i];
		}
	}
	return SmartPhones();
}
void Inventory::removeSmartPhone(int id)
{
	int position = -1;
	for (int i = 0; i < this->smartp.size(); i++) {
		if (this->smartp[i].getId() == id) {
			position = i;
			break;
		}
	}
	if (position == -1) {
		return;
	}
	this->smartp.erase(smartp.begin()+position);

}
//Watches
void Inventory::addWatch(const Watches& rhs)
{
	watch.push_back(rhs);
}
Watches Inventory::searchWatch(int idx)
{
	for (int i = 0; i < this->smartp.size(); i++) {

		if (this->watch[i].getId() == idx) {
			return this->watch[i];
		}
	}
	return Watches();
}
void Inventory::removeWatch(int id)
{
	int position = -1;
	for (int i = 0; i < this->watch.size(); i++) {
		if (this->watch[i].getId() == id) {
			position = i;
			break;
		}
	}
	if (position == -1) {
		return;
	}
	this->watch.erase(watch.begin()+position);
}



void Inventory::DisplayLaptop() {
	for (int i = 0; i < this->laptop.size(); i++) {
		cout << " Name: " << laptop[i].getName() << " ";
		cout << "| Battery Life: " << laptop[i].Getbaterry_life() << "h ";
		cout << "| Brand: " << laptop[i].getCategory() << " ";
		cout << "| Price: " << laptop[i].getPrice() << " lv ";
		cout << "| Proccesor: " << laptop[i].getProcesor() << " ";
		cout << "| Quantity:  " << laptop[i].getQuantity() << " ";
		cout << "| Resolution : " << laptop[i].Getresulution() << " inch" << endl;
		cout << "| Item ID: " << laptop[i].getId() << endl;
	}
}
void Inventory::DisplaySmartPhones() {
	for (int i = 0; i < this->smartp.size(); i++) {
		cout << " Name: " << smartp[i].getName() << " ";
		cout << "| Battery Life: " << smartp[i].Getbaterry_life() << "h ";
		cout << "| Brand: " << smartp[i].getCategory() << " ";
		cout << "| Price: " << smartp[i].getPrice() << " lv ";
		cout << "| Quantity:  " << smartp[i].getQuantity() << " ";
		cout << "| Resolution : " << smartp[i].Getresulution() << " inch" << endl;
		cout << "| Item ID: " << smartp[i].getId() << endl;
		cout << "| Color: " << smartp[i].GetColor() << endl;
		cout << "| Operative System: " << smartp[i].GetOperative_Ststem() << endl;
		cout << "| Ram: " << smartp[i].GetRam() << endl;
		cout << "| Weight: " << smartp[i].GetWeight() << endl;
	}
}

void Inventory::DisplayWatches() {
	for (int i = 0; i < this->watch.size(); i++) {
		cout << " Name: " << watch[i].getName() << " ";
		cout << "| Brand: " << watch[i].getCategory() << " ";
		cout << "| Price: " << watch[i].getPrice() << " lv ";
		cout << "| Quantity:  " << watch[i].getQuantity() << " ";
		cout << "| Item ID: " << watch[i].getId() << endl;

		cout << "| Watch Glass" << watch[i].GetWatchGlass() << endl;
		cout << "| Watch Material: " << watch[i].GetWatchMaterial() << endl;
		cout << "| Watch Movement: " << watch[i].GetWatchMovement() << endl;
		cout << "| Watch WaterRessistent: " << watch[i].GetWatchWaterRess() << endl;
	}
}
void Inventory::Display() {
	DisplayLaptop();
	//DisplaySmartPhones();
	//DisplayWatches();
}