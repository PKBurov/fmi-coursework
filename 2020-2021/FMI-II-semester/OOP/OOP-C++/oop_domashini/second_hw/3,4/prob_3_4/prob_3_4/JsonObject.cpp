#include "JsonObject.hpp"
#pragma warning(disable: 4996)
#include<cstring>

//JsonObject::JsonObject() :value(0) {
//	this->key = new char[1];
//	this->key[0] = '\0';
//}
//JsonObject::JsonObject(const char* key, int value) : value(value) {
//	this->key = new char[strlen(key) + 1];
//	strcpy(this->key, key);
//}
//
//JsonObject::~JsonObject() {
//	delete[] this->key;
//}
//
//JsonObject::JsonObject(const JsonObject& rhs) :value(rhs.value) {
//	delete[] this->key;
//	this->key = new char[strlen(rhs.key) + 1];
//	strcpy(this->key, key);
//}
//
//JsonObject& JsonObject::operator=(const JsonObject& rhs) {
//	if (this != &rhs) {
//		this->value = rhs.value;
//		delete[] this->key;
//		this->key = new char[strlen(rhs.key) + 1];
//		strcpy(this->key, rhs.key);
//	}
//	return *this;
//}
////char* JsonObject::getKey() const {
////	return this->key;
////}
//
//int JsonObject::getValue() {
//	return this->value;
//}