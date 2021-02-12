#ifndef PROTECTEDVALUE_H
#define PROTECTEDVALUE_H

template<typename T>
class ProtectedValue
{
    public:
        ProtectedValue();
        ProtectedValue(T,unsigned);
        ~ProtectedValue(){};
        T getValue(const unsigned);
        unsigned getCode()const;


    private:
        T value;
        unsigned int code;
};

#endif // PROTECTEDVALUE_H
