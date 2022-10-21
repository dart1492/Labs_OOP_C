#pragma once
#include "Rectangle.h"
#include <cmath>
class Pyramid : public Rectangle
{

private:
	double height;

public:
	Pyramid();

	Pyramid(double length, double width, double height);
	
	void view();

	~Pyramid();

	double surface_area();

	double volume();

	

};

