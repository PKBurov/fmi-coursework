#pragma once
#include <cstring>
#include "product.h"

class SmartPhones : public Item {
public:
	SmartPhones();
	~SmartPhones();

	char* GetColor()const;
	char* GetOperative_Ststem() const;
	int Getbaterry_life() const;
	int Getresulution() const;
	int GetRam() const;
	int GetWeight() const;


	void SetRess(int);
	void SetBattery(int);
	void SetWeight(int);
	void SetRam(int);
	void SetColor(const char* Color);
	void SetOperative_System(const char* System);

	SmartPhones& operator=(const SmartPhones& rhs);
	SmartPhones(const SmartPhones& rhs);

private:
	int resulution = 0;
	int baterry_life = 0;
	int weight = 0;
	int ram = 0;
	char* color = nullptr;
	char* operative_system = nullptr;
};


