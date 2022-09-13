#include "Cus_arr.h"

Cus_arr::Cus_arr(std::string name, int size) {
	this->name = name;
	this->size = size;
	this->arr = new int[size];

	std::cout << this->name << " obj" << " parametrized constructor called..." << std::endl;
}

Cus_arr::Cus_arr() {
	this->name = "default";
	this->size = 0;
	this->arr = nullptr;

	std::cout << this->name << " obj" << " default constructor called..." << std::endl;
}

Cus_arr::Cus_arr(const Cus_arr& obj) {
	this->arr = new int[obj.size];
	this->size = obj.size;
	for (int i = 0; i < size; i++) {
		this->arr[i] = obj.arr[i];
	}

	this->name = obj.name + " copy";
	
}

Cus_arr::~Cus_arr() {
	if (this->size != 0) {
		delete [] arr;
		this->size = 0;
		// this->arr = nullptr;
	}

	std::cout << this->name << " obj" << " destructor called..." << std::endl;
}

int Cus_arr::len() {
	return this->size;
}

int& Cus_arr::operator[](int index) {
    if (index >= this->size) {
        std::cout << "Array index out of bounds" << std::endl;
        exit(0);
    }
    return arr[index];
}


Cus_arr Cus_arr::operator = (Cus_arr test) {
	if (this == &test) return *this;

	std::size_t newSize = test.size;
	int* newArray = newSize ? new int[newSize]() : nullptr; // (3)
	std::copy(test.arr, test.arr + newSize, newArray); // (3)
	delete[] arr;
	this->size = newSize;
	this->arr = newArray;

	return *this;
}

Cus_arr Cus_arr::operator+(Cus_arr second) {
	std::string new_name = this->name + "+" + second.name;
	Cus_arr result(new_name, this->size + second.size);

	int i = 0;
	while (i != this->size) {
		result[i] = this->arr[i];
		i++;
	}

	int j = i;
	i = 0;

	while (i != second.size) {
		result[j] = second[i];
		j++;
		i++;
	}

	return result;
}

std::ostream& operator <<(std::ostream& output, Cus_arr& obj) {
	output << obj.name << ": ";
	for (int i = 0; i < obj.size; i++)
	{
		output << obj.arr[i] << " ";
	}
	output << "\n";
	return output;
}

std::istream& operator >>(std::istream& input, Cus_arr& Arr) { //перевантаження введення
	for (int i = 0; i < Arr.size; i++)
	{
		input >> Arr.arr[i];
	}
	return input;
}


