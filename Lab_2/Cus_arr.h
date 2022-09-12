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
	Cus_arr(std::string name, int size) {
		this->name = name;
		this->size = size;
		this->arr = new int(size);

		std::cout << "Parametrized constructor called..." << std::endl;
	}

	Cus_arr() {
		this->name = "default";
		this->size = 0;
		this->arr = nullptr;

		std::cout << "Default constructor called..." << std::endl;
	}

	~Cus_arr() {
		if (this->size != 0) {
			delete[] arr;
			this->size = 0;
			this->arr = nullptr;
		}

		std::cout << "Destructor called..." << std::endl;
	}
};

