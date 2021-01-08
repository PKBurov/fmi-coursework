#include "ProtectedValue.h"
#include <exception>
using namespace std;
template<typename T>
ProtectedValue<T>::ProtectedValue()
{
    //ctor
	this->code = 0;
	this->value = 0;
}
template<typename T>
ProtectedValue<T>::ProtectedValue(T value,unsigned code)
{
    this->code=code;
    this->value=value;
}

template<typename T>
T ProtectedValue<T>::getValue(unsigned code){
    if(getCode()==code){
        return this->value;
    }
    else{
        return 0;
    }
}

template<typename T>
unsigned ProtectedValue<T>::getCode()const{
    return this->code;
}
