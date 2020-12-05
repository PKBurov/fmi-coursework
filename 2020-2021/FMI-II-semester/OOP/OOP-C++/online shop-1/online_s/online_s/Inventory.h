#pragma once
#include "product.h"
//#include "vector.h"
#include <vector>
#include "Watches.h"
#include "SmartPhones.h"
#include "Laptop.h"
class Inventory {
public:
	//void addItem(const Item&);
	//Item search(int);
	//void RemoveItem(int);
	//void Display();

	void addLaptop(const Laptop& rhs);
	Laptop searchLaptop(int id);
	void removeLaptop(int id);
	
	void addSmartPhone(const SmartPhones& rhs);
	SmartPhones searchSmartp(int idx);
	void removeSmartPhone(int id);

	void addWatch(const Watches& rhs);
	Watches searchWatch(int idx);
	void removeWatch(int id);
	



	void Display();
	void DisplayLaptop();
	void DisplaySmartPhones();
	void DisplayWatches();

private:
	vector<SmartPhones> smartp;
	vector<Laptop> laptop;
	vector<Watches> watch;
};
