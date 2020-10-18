#include "ProtectedArray.h"
template<typename T>
ProtectedArray<T>::ProtectedArray()
{
    this->arr=nullptr;
    this->sz=0;
}
template<typename T>
ProtectedArray<T>::ProtectedArray(ProtectedValue<T>* arr,int sz)
{
    this->sz=sz;
    this->arr = new ProtectedValue<T>[sz];
    for(int i=0;i<sz;i++){
        this->arr[i]=arr[i];
    }
}
template<typename T>
ProtectedArray<T>::~ProtectedArray()
{
    delete[] this->arr;
}
template<typename T>
ProtectedArray<T>::ProtectedArray(const ProtectedArray&)
{
	this->sz = sz;
	this->arr = new ProtectedValue<T>[sz];
	for (int i = 0; i < sz; i++){
		this->arr[i] = arr[i];
	}
}
template<typename T>
ProtectedArray<T> ProtectedArray<T>::operator=(const ProtectedArray& other)
{
    if(this!=&other){
        delete[] this->arr;
        this->sz=sz;
        this->arr = new ProtectedValue<T>[sz];
        for(int i=0;i<sz;i++){
            this->arr[i]=arr[i];
        }
    }
    return *this;

}
template<typename T>
void ProtectedArray<T>::addToArr(T value,unsigned int code){
    ProtectedValue<T>* newArr=new ProtectedValue<T>[sz+1];
    for(int i=0;i<sz;i++){
        newArr[i]=arr[i];
    }
    ProtectedValue<T> element(value,code);
    newArr[sz]=element;
    this->sz++;

}
template<typename T>
ProtectedValue<T> ProtectedArray<T>::getElementAtIndx(int index,unsigned int code){
    return arr[index].getValue(code);
}
