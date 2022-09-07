#pragma once
#include <iostream>

class Test
{
private:
	int first_int;
	int second_int;
public:
	// default
	Test()  {
		this->first_int = 0;
		this->second_int = 0;
	} 
	// with params
	Test(int first, int second) {
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

		this->first_int = first;
		this->second_int = second;
		
	}
	//Set first
	void set_first(int first);

	void set_second(int second);

	int get_first();

	int get_second();

	void print_fields();

	bool check(int x);

	Test operator + (Test second);

	Test operator + (int second);

	friend int operator + (int, Test&);

	Test operator ++();

	Test operator ++(int);
};






