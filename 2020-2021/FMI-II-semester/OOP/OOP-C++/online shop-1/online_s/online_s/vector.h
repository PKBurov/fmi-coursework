//#pragma once
//template<typename T>
//class Vector
//{
//private:
//	T* elements;
//
//	int size = 0;
//	int length = 0;
//
//	void ResizeArray();
//
//	void Shift_Array_To_Right(int index);
//	void Shift_Array_To_Left(int index);
//
//	bool NeedResize();
//
//
//public:
//	Vector();
//	Vector(const T elements[], const int size);
//	Vector(const Vector& Vector);
//	~Vector();
//
//	int GetLength();
//	int GetSize();
//	T GetElement(int index);
//
//	bool AddElement(T element);
//	bool AddElementOnIndex(T element, int index);
//
//	bool DeleteElement(int index);
//	bool DeleteAll();
//
//	Vector<T> operator =(const Vector<T>& obj);
//	T operator[](int);
//};
//
//template<typename T>
//Vector<T>::Vector()
//{
//	this->elements = new T[0];
//}
//
//template<typename T>
//Vector<T>::Vector(const T elements[], const int size)
//{
//	this->elements = new T[size];
//
//	this->size = size;
//	this->length = size;
//
//	for (int i = 0; i < this->length; i++)
//	{
//		this->elements[i] = elements[i];
//	}
//}
//
//template<typename T>
//inline Vector<T>::Vector(const Vector& Vector)
//{
//	this->length = Vector.length;
//	this->size = Vector.size;
//
//	this->elements = new T[this->size];
//
//	for (int i = 0; i < Vector.length; i++)
//	{
//		this->elements[i] = Vector.elements[i];
//	}
//}
//
//template<typename T>
//inline Vector<T>::~Vector()
//{
//	delete[] elements;
//}
//
//template<typename T>
//void Vector<T>::ResizeArray() {
//	this->size = (this->size + 1) * 2;
//	int size = this->size;
//	int length = this->length;
//
//	T* elements = new T[size];
//
//	for (size_t i = 0; i < length; i++)
//	{
//		elements[i] = this->elements[i];
//	}
//
//	delete[] this->elements;
//
//	this->elements = elements;
//
//	this->size = size;
//}
//
//template<typename T>
//void Vector<T>::Shift_Array_To_Right(int index)
//{
//	for (int i = this->length - 1; i >= index; i--)
//	{
//		this->elements[i + 1] = this->elements[i];
//	}
//
//}
//
//template<typename T>
//void Vector<T>::Shift_Array_To_Left(int index)
//{
//	for (int i = index + 1; i < this->length; i++)
//	{
//		this->elements[i - 1] = this->elements[i];
//	}
//
//	this->elements[this->length - 1] = T();
//}
//
//template<typename T>
//bool Vector<T>::NeedResize()
//{
//	if (this->size == this->length) {
//		return true;
//	}
//	return false;
//}
//
//template<typename T>
//int Vector<T>::GetLength()
//{
//	return this->length;
//}
//
//template<typename T>
//int Vector<T>::GetSize()
//{
//	return this->size;
//}
//
//template<typename T>
//T Vector<T>::GetElement(int index)
//{
//	if (this->length <= index) {
//		return T();
//	}
//
//	return this->elements[index];
//}
//
//template<typename T>
//bool Vector<T>::AddElement(T element)
//{
//	if (this->NeedResize())
//		this->ResizeArray();
//
//	this->elements[this->length] = element;
//	this->length++;
//
//	return true;
//}
//
//template<typename T>
//bool Vector<T>::AddElementOnIndex(T element, int index)
//{
//	if (index >= this->length) {
//		return false;
//	}
//
//	this->Shift_Array_To_Right(index);
//
//	this->elements[index] = element;
//	this->length++;
//
//	return true;
//}
//
//template<typename T>
//bool Vector<T>::DeleteElement(int index)
//{
//	if (index >= this->length)
//		return false;
//
//	this->Shift_Array_To_Left(index);
//	this->length--;
//
//	return true;
//}
//
//template<typename T>
//inline bool Vector<T>::DeleteAll()
//{
//	delete[] this->elements;
//
//	this->elements = new T[0];
//
//	return true;
//}
//
//template<typename T>
//inline Vector<T> Vector<T>::operator=(const Vector<T>& obj)
//{
//	if (this != &obj) {
//		this->length = obj.length;
//		this->size = obj.size;
//
//		delete[] this->elements;
//
//		this->elements = new T[this->size];
//
//		for (int i = 0; i < obj.length; i++)
//		{
//			this->elements[i] = obj.elements[i];
//		}
//	}
//
//	return *this;
//}
//
//template<typename T>
//inline T Vector<T>::operator[](int index)
//{
//	if (index >= size)
//		return T();
//
//	return this->elements[index];
//}
//
