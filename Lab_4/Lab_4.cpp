
#include <iostream>
#include "Pyramid.h"

int main()
{
	Rectangle first_rec(5, 6);
	first_rec.view();
	std::cout << first_rec.area() << std::endl;

	Pyramid first(4,5,6);
	first.view();
	first.get_length();
	std::cout << "Area, inherited from the rectangle: " << first.area() << " Surface area: " << first.surface_area() << std::endl;
}

