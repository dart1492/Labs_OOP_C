#include "Test.h"


void Test::set_first(int first) {
	try
	{
		if (this->second_int < first) {
			std::string e = "first cant be bigger";
			throw e;
		}

	}
	catch (std::string e)
	{
		std::cout << e << std::endl;
		exit(1);
	}

	this->first_int = first;
}

void Test::set_second(int second) {
	try
	{
		if (second < this->first_int) {
			std::string e = "first cant be bigger";
			throw e;
		}

	}
	catch (std::string e)
	{
		std::cout << e << std::endl;
		exit(1);
	}
	
	this->second_int = second;
}

int Test::get_first() {
	return this->first_int;
}

int Test::get_second() {
	return this->second_int;
}

void Test::print_fields() {
	std::cout << this->first_int << " " << this->second_int << std::endl;
}

bool Test::check(int x) {
	if (x >= this->first_int && x <= this->second_int) {
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

void Test::operator ++() {
	++this->first_int;
	++this->second_int ;
}

void Test::operator ++(int) { // int param indicates postfix
	this->first_int++;
	this->second_int++;
}


