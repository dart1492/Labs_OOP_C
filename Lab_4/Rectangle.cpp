#include "Rectangle.h"
Rectangle::Rectangle() {
	length = 1;
	width = 1;
	std::cout << "Default constructor of the base class..." << std::endl;
}

Rectangle::Rectangle(double length, double width) {
	this->length = length;
	this->width = width;
	std::cout << "Parametrized constructor of the base class..." << std::endl;
}

Rectangle::~Rectangle() {
	std::cout << "Base class destructor..." << std::endl;
}

double Rectangle::area() {
	return length * width;
}

double Rectangle::perimeter() {
	return length * 2 + width * 2;
}

void Rectangle::view() {
	std::cout << "length: " << this->length << ", width:" << this->width << std::endl;
}