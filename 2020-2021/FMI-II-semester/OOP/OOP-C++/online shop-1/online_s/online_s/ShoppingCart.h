#pragma once
#include "product.h"
#include "Laptop.h"
#include "SmartPhones.h"
#include "Watches.h"
#include <vector>
//#include "vector.h"
class ShoppingCart{
public:
	void addItem(const Item& item, const Laptop& laptop);
	Item searchItem(int ID);
	void RemoveItem(int idx );


	void Display(const Item& item, const SmartPhones& smp);
	void Display(const Item& item, const Watches& wch);
	void Display(const Item& item, const Laptop& lap);

	void addItem(const Item& rhs, const SmartPhones& smp);
	void addItem(const Item& rhs, const Watches& wchs);

private:
	vector<Item> IT;
	vector<Laptop> laptop;
	vector<SmartPhones> smp;
	vector<Watches> wchs;
	
};
