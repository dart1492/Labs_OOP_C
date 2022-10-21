#pragma once
#include <iostream>
#include <string>
using namespace std;

class test
{
private:
	int* arr;
	int size;
	string name;

public:

	test();

	test(string arr_name, int arr_size);

	test(const test& array);

	~test();

	int& operator[](int index);

	

	test operator- (test obj);

	test& operator= (const test arr);

	friend istream& operator >>(istream& input, test& Arr);

	friend ostream& operator << (ostream& output, test& Arr);

	test& next();

};

