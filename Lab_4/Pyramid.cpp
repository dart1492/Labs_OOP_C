#include "Pyramid.h"

Pyramid::Pyramid() {
	// Rectangle();
	this->height = 1;
	std::cout << "Default constructor of the derived class" << std::endl;
}

Pyramid::Pyramid(double length, double width, double height) : Rectangle(length, width) {
	this->height = height;
	std::cout << "Parametrized constructor of the derived class" << std::endl;
}

Pyramid::~Pyramid() {
	std::cout << "Derived class destructor..." << std::endl;
}

double Pyramid::surface_area() {
	double side_area = sqrt((this->length / 2.0) * (Rectangle::get_length() / 2.0) + height * height)
		* Rectangle::perimeter() / 2.0;

	return side_area * Rectangle::area();
}

double Pyramid::volume() {
	return (Rectangle::area() * this->height) / 3.0;
}

void Pyramid::view() {
	Rectangle::view();
	std::cout << "Additional parameter (height): " << this->height << std::endl;
}

