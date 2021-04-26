//#include"JsonArray.hpp"
//#pragma warning(disable: 4996)
//#include<iostream>
//using namespace std;
//JsonArr::JsonArr() :arr(nullptr), size(0) {
//}
//JsonArr::~JsonArr() {
//	delete[] this->arr;
//}
//JsonArr::JsonArr(const JsonArr& rhs) {
//	if (rhs.size != 0) {
//		this->size = rhs.size;
//		this->arr = new JsonObject[rhs.size];
//		for (int i = 0; i < rhs.size; i++) {
//			this->arr[i] = rhs.arr[i];
//		}
//	}
//}
//JsonArr& JsonArr::operator=(const JsonArr& rhs) {
//	if (this != &rhs && rhs.size != 0) {
//		this->size = rhs.size;
//		delete[] this->arr;
//		this->arr = new JsonObject[rhs.size];
//		for (int i = 0; i < rhs.size; i++) {
//			this->arr[i] = rhs.arr[i];
//		}
//	}
//	return *this;
//}
//bool Compare(const char* lhs, const char* rhs) {
//	for (size_t i = 0; lhs[i] != '\0'; i++) {
//		if (lhs[i] != rhs[i]) {
//			return false;
//		}
//	}
//	return true;
//}
//int JsonArr::ReturnValue(const char* key) const {
//	int idx;
//	for (int i = 0; i < this->size; i++) {
//		if (Compare(this->arr[i].getKey(), key)) {
//			idx = i;
//			break;
//		}
//	}
//	return this->arr[idx].getValue();
//}
//int JsonArr::DeleteByKey(const char* key) {
//	int idx, value;
//	for (int i = 0; i < this->size; i++) {
//		if (Compare(this->arr[i].getKey(), key)) {
//			idx = i;
//			break;
//		}
//	}
//	if (this->size > 1) {
//		JsonObject* newArr = new JsonObject[this->size - 1];
//		for (size_t i = 0; i < this->size - 1; i++) {
//			if (i < idx) {
//				newArr[i] = this->arr[i];
//			}
//			else {
//				newArr[i] = this->arr[i + 1];
//			}
//		}
//		value = this->arr[idx].getValue();
//		delete[] this->arr;
//		this->arr = newArr;
//		this->size--;
//	}
//	else {
//		value = this->arr[idx].getValue();
//		delete[] this->arr;
//		this->size = 0;
//	}
//	return value;
//}
//void JsonArr::AddByValueAndKey(const char* key, const int value) {
//	JsonObject curr(key, value);
//	JsonObject* newArr = new JsonObject[this->size + 1];
//	for (int i = 0; i < this->size; i++) {
//		newArr[i] = this->arr[i];
//	}
//	newArr[this->size] = curr;
//	delete[] this->arr;
//	this->arr = newArr;
//	this->size++;
//}
//ostream& operator<<(ostream& os, JsonArr& rhs) {
//	os << "[" << endl;
//	for (int i = 0; i < rhs.size - 1; i++) {
//		os << "\t" << "{" << endl << "\t\t" << "\"" << rhs.arr[i].getKey() << "\": \"" << rhs.arr[i].getValue() << "\"" << endl << "\t}," << endl;
//	}
//	os << "\t" << "{" << endl << "\t\t" << "\"" << rhs.arr[rhs.size - 1].getKey() << "\": \"" << rhs.arr[rhs.size - 1].getValue() << "\"" << endl << "\t}" << endl << "]" << endl;
//	return os;
//}