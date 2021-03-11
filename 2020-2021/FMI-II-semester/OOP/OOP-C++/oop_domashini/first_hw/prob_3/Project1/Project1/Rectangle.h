#pragma once
class Shape {
	double x1, x2;
	double y1, y2;
	double diagonal;
	double area;
	double length;
	double width;
public:
	Shape();
	Shape(const Shape& CopyFrom);
	Shape& operator=(const Shape& other);

	void set_Diag(double width, double length);
	void set_Area(int length, int width);
	void set_Len(double x1, double x2);
	void set_Width(double y1, double y2);
	void set_x1_Cord(double newX1);
	void set_x2_Cord(double newX2);
	void set_y1_Cord(double newY1);
	void set_y2_Cord(double newY2);

	const double get_Diag() const;
	const double get_Area() const;
	const double get_Len() const;
	const double get_Width() const;
	const double get_x1_Cord() const;
	const double get_x2_Cord() const;
	const double get_y1_Cord() const;
	const double get_y2_Cord() const;

	void Create();
};
