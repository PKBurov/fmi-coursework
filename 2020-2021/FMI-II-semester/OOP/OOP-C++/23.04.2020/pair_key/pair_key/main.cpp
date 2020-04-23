#include<iostream>
#include<cstring>
#include<vector>

template <class VALUE>
class Value
{
public:
	VALUE value;
};

template <class VALUE,class KEY>
class Pair : public Value<VALUE> {
public:
	KEY key;
};

int main() {
	Value<int> v;
	v.value = 12;
	Pair<char, int>p;
	p.key = 'a';
	p.value = 'a';
	std::cout << "Char " << p.key << " has ASCII value " << p.value << "\n";
}