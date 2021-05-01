#pragma once
#include<cstring>
template<class T>

class JsonObject {
private:
	char* key;
	T value;
public:
	JsonObject();
	JsonObject(const char* key, int value);
	
	JsonObject<T>& operator=(const JsonObject<T>&);
	JsonObject(const JsonObject<T>&); 

	~JsonObject();

	char* getKey() const;
	T getValue() const;
};


template<class T>
inline JsonObject<T>::JsonObject() :value(0)
{
	this->key = new char[1];
	this->key[0] = '\0';
}
template<class T>
inline JsonObject<T>::JsonObject(const char* key, int value) : value(value)
{
	this->key = new char[strlen(key) + 1];
	strcpy(this->key, key);
}
template<class T>
inline JsonObject<T>& JsonObject<T>::operator=(const JsonObject<T>&rhs)
{
	if (this != &rhs) {
		this->value = rhs.value;
		delete[] this->key;
		this->key = new char[strlen(rhs.key) + 1];
		strcpy(this->key, rhs.key);
	}
	return *this;
}
template<class T>
inline JsonObject<T>::JsonObject(const JsonObject<T>& rhs) : value(rhs.value)
{
	delete[] this->key;
	this->key = new char[strlen(rhs.key) + 1];
	strcpy(this->key, key);
}
template<class T>
inline JsonObject<T>::~JsonObject()
{
	delete[] this->key;
}
template<class T>
inline char* JsonObject<T>::getKey() const
{
	return this->getKey;
}
template<class T>
inline T JsonObject<T>::getValue() const
{
	return this->value;
}


