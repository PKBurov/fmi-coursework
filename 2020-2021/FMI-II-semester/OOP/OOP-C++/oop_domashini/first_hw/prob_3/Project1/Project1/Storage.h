#include "Rectangle.h"
class Storage {
	Shape* rectangles;
	unsigned int count_rectangles;
public:
	Storage();
	~Storage();
	Storage(const Storage& CopyFrom);
	Storage& operator=(const Storage& other);
	void Add(Shape New_R);
	void Show();
};
