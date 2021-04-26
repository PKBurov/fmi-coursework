#pragma once
#include"JsonObject.hpp"
#pragma warning(disable: 4996)
#include<iostream>

using namespace std;

template<class T>
class JsonArr {
private:
	JsonObject<T>* arr;
	int size;
public:
	~JsonArr();
	JsonArr<T>() : arr(nullptr), size(0) {}
	JsonArr(const JsonArr<T>&rhs);
	JsonArr<T>& operator=(const JsonArr<T>&);
	T ReturnValue(const char*) const;
	T DeleteByKey(const char*);
	void AddByValueAndKey(const char*, const int);
};
template<class T>
inline JsonArr<T>::~JsonArr()
{
	delete[] this->arr;
}

template<class T>
inline JsonArr<T>::JsonArr(const JsonArr<T>&rhs)
{
	if (rhs.size != 0) {
		this->size = rhs.size;
		this->arr = new JsonObject[rhs.size];
		for (int i = 0; i < rhs.size; i++) {
			this->arr[i] = rhs.arr[i];
		}
	}
}

template<class T>
inline JsonArr<T>& JsonArr<T>::operator=(const JsonArr<T>&rhs)
{
	if (this != &rhs && rhs.size != 0) {
		this->size = rhs.size;
		delete[] this->arr;
		this->arr = new JsonObject[rhs.size];
		for (int i = 0; i < rhs.size; i++) {
			this->arr[i] = rhs.arr[i];
		}
	}
	return *this;
}
template<class T>
inline T JsonArr<T>::ReturnValue(const char*key) const
{
	int idx;
	for (int i = 0; i < this->size; i++) {
		if (Compare(this->arr[i].getKey(), key)) {
			idx = i;
			break;
		}
	}
	return this->arr[idx].getValue();
}
template<class T>
inline T JsonArr<T>::DeleteByKey(const char*key)
{
	int idx, value;
	for (int i = 0; i < this->size; i++) {
		if (Compare(this->arr[i].getKey(), key)) {
			idx = i;
			break;
		}
	}
	if (this->size > 1) {
		JsonObject* newArr = new JsonObject[this->size - 1];
		for (size_t i = 0; i < this->size - 1; i++) {
			if (i < idx) {
				newArr[i] = this->arr[i];
			}
			else {
				newArr[i] = this->arr[i + 1];
			}
		}
		value = this->arr[idx].getValue();
		delete[] this->arr;
		this->arr = newArr;
		this->size--;
	}
	else {
		value = this->arr[idx].getValue();
		delete[] this->arr;
		this->size = 0;
	}
	return value;
}
template<class T>
inline void JsonArr<T>::AddByValueAndKey(const char*key, const int value)
{
	JsonObject curr(key, value);
	JsonObject* newArr = new JsonObject[this->size + 1];
	for (int i = 0; i < this->size; i++) {
		newArr[i] = this->arr[i];
	}
	newArr[this->size] = curr;
	delete[] this->arr;
	this->arr = newArr;
	this->size++;
}
bool Compare(const char* lhs, const char* rhs) {
	int i = 0;
	do{
		if (lhs[i] != rhs[i]) {
			return false;
		}
		i++;

	} while (lhs[i] != '\0');
		return true;
}