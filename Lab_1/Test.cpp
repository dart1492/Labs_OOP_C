#include "Test.h"

void Test::set_values(int first, int second) {

	try
	{
		if (second < first) {
			std::string e = "first cant be bigger";
			throw e;
		}

	}
	catch (std::string e)
	{
		std::cout << e << std::endl;
		exit(1);
	}

	this->first = first;
	this->second = second;
}


void Test::print_fields() {
	std::cout << this->first << " " << this->second << std::endl;
}

bool Test::check(int x) {
	if (x >= this->first && x <= this->second) {
		return true;
	}
	else {
		return false;
	}
}

Test Test::operator + (Test second) {
	Test res(this->get_first() + second.get_first(), this->get_second() + second.get_second());
	return res;
}

Test Test::operator + (int second) {
	Test res(this->get_first() + second, this->get_second() + second);
	return res;
}

Test operator+ (int first, Test& d1) {
	Test res(d1.get_first() + first, d1.get_second() + first);
	return res;
}
