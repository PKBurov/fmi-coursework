#pragma once
#include <cstring>
#include "product.h"
#include <string>
using namespace std;
class Laptop : public Item {
public:
	Laptop() {
	};
	~Laptop() {
	};
	
	string getProcesor() const;
	int Getbaterry_life() const;
	int Getresulution() const;
	void setRess(int);
	void setBattery(int);
	void SetProcesor(string newName);
	Laptop& operator=(const Laptop& rhs);
	Laptop(const Laptop& rhs);

private:
	int resulution = 0;
	int baterry_life = 0;
	string procesor;
};

