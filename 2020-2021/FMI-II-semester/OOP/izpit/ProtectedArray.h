#ifndef PROTECTEDARRAY_H
#define PROTECTEDARRAY_H
#include"ProtectedValue.h"
template<typename T>
class ProtectedArray
{
    public:
        ProtectedArray();
        ProtectedArray(ProtectedValue<T>*,int sz);
        ~ProtectedArray();

        ProtectedArray(const ProtectedArray&);

        ProtectedArray operator=(const ProtectedArray&);

        void addToArr(T value,unsigned int code);

        ProtectedValue<T> getElementAtIndx(int index,unsigned int code);

    protected:

    private:
        ProtectedValue<T>* arr;
        int sz;
};

#endif // PROTECTEDARRAY_H
