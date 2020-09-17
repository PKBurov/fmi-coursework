#pragma once
#include <cstring>
#include "JSONObject.h"
#include <iostream>
#include "envelop.h"
#include <vector>

template <class T>
class JSONArray : public envelop <T> {
private:
	std::vector<envelop<T>*> array;

public:

	~JSONArray();

	JSONObject<T> operator[] (const int& pos) const;
	void insert(const char* key, T value);

	T get_value(const char* key) const;

	int get_size() const;
	Objects getType() const override;
};

template <class T>
JSONArray<T>::~JSONArray<T>()
{
	delete[] this->array;
	for (int i = 0; i < get_size() ; i++){
		delete temp[i];
	}
	delete[] temp;
}


template <class T>
JSONObject<T> JSONArray<T>::operator[] (const int& pos) const
{
	return this->array[pos];
}


template <class T>
void JSONArray<T>::insert(const char* key, T value)
{
	JSONObject<T>* temp = new JSONObject<T>();
	temp->set_key(key);
	temp->set_value(value);

	this->array.push_back(temp);
}

template <class T>
T JSONArray<T>::get_value(const char* key) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (strcmp(key, this->array[i].get_key()) == 0)
		{
			return this->array[i].get_value();
		}
	}
	std::cout << "key not found"; // Exception ?
	return T();
}

template <class T>
int JSONArray<T>::get_size() const
{
	return this->size;
}

template<class T>
inline Objects JSONArray<T>::getType() const
{
	return objType;
}