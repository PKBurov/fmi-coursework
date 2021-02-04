#include "IntCounter.h"

IntCounter::IntCounter(const int* size)
{
	a_Size = *size;
	a_Buffer = new int[a_Size];
	r_Count = 1;
}
IntCounter::IntCounter(IntCounter& other)
	:a_Size(other.a_Size),r_Count(other.r_Count)
{
	int other_count = 0;
	other_count++;
	a_Buffer = new int[a_Size + 1];
	for (unsigned int i = 0; i < a_Size; i++){
		a_Buffer[i] = other.a_Buffer[i];
	}
	r_Count = (other.r_Count++) + (other_count);
}
IntCounter::~IntCounter() {
	r_Count--;
	delete[]a_Buffer;
}
int IntCounter::get_count() const
{
	return r_Count;
}
