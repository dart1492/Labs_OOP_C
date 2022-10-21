#pragma once
#include <iostream>
class Rectangle
{
protected:
	double length;
private:
	double width;

public:
	Rectangle();

	Rectangle(double length, double width);

	~Rectangle();

	double area();

	double perimeter();

	void view();

	double get_length() {
		return length;
	}

	double get_width() {
		return width;
	}
};

