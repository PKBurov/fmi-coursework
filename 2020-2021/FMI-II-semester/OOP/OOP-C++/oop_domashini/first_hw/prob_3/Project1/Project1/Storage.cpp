#include "Storage.h"
#include <iostream>
#include <cstring>
Storage::Storage() {
	count_rectangles = 0;
	Shapes = new Shape[count_rectangles];
}
Storage::~Storage() {
	delete[] Shapes;
}
Storage::Storage(const Storage& CopyFrom) {
	count_rectangles = CopyFrom.count_rectangles;
	for (size_t i = 0; i < count_rectangles; i++) {
		Shapes[i] = CopyFrom.Shapes[i];
	}
}
Storage& Storage::operator=(const Storage& other) {
	return *this;
}
void Storage::Add(Shape New_R) {
	std::cout << "______________" << std::endl;
	Shape* NewShapes = new Shape[count_rectangles + 1];
	for (unsigned int i = 0; i < count_rectangles; i++) {
		NewShapes[i] = Shapes[i];
	}
	NewShapes[count_rectangles] = New_R;
	delete[] Shapes;
	Shapes = NewShapes;
	count_rectangles++;
	std::cout << "Shape added! " << std::endl;
}
void Storage::Show() {
	if (count_rectangles > 0) {
		std::cout << "The Shapes currently are: " << std::endl;
		for (unsigned int i  = 0; i < count_rectangles; i++) {
			std::cout << "Shape number " << i + 1 << std::endl;
			std::cout << "Specifics: " << std::endl;
			std::cout << "Point 1: " << Shapes[i].get_x1_Cord() << ";" << Shapes[i].get_y2_Cord() << std::endl;
			std::cout << "Point 2: " << Shapes[i].get_x2_Cord() << ";" << Shapes[i].get_y2_Cord() << std::endl;
			std::cout << "Diagonal: " << Shapes[i].get_Diagonal() << std::endl;
			std::cout << "Area: " << Shapes[i].get_Area() << std::endl;
			std::cout << "Length: " << Shapes[i].get_Len() << std::endl;
			std::cout << "Width: " << Shapes[i].get_Width() << std::endl;
		}
	}else {
		std::cout << "No Shapes" << std::endl;
	}
}