#pragma once

class Car {

private:

	char* number;
	char* VIN;
	char* brand;
	char* model;
	char* color;
	char* horesPower;
	char* year;






public:

	Car();
	Car(const char* number, const char* VIN, const char* brand, const char* model, const char* color, int horesPower, int year);
	Car(const Car& other);
	Car operator =(const Car& other);
	Car();

	//Setters:
	void setColor(const char* newColor);

	//Getters 
	const char* getNumber() const;

	void showInfo() const;

	//operators
	bool operator==(const Car& other) const;
	bool operator!=(const Car& other) const;
	bool operator


};