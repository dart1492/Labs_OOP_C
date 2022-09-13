#pragma once
#include <string>
#include <iostream>

class Cus_arr
{
private:
	std::string name;
	int size;
	int* arr;

public:

	Cus_arr(std::string name, int size);

	Cus_arr();

	Cus_arr(const Cus_arr &obj);

	~Cus_arr();

	int len();

	int& operator[](int);

	Cus_arr operator+(Cus_arr second);

	Cus_arr operator = (Cus_arr test);

	friend std::ostream& operator <<(std::ostream& output, Cus_arr& obj);

	friend std::istream& operator >>(std::istream& output, Cus_arr& obj);
};


