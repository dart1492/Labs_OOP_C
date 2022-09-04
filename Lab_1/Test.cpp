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