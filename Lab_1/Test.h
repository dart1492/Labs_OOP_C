#pragma once
#include <iostream>

class Test
{

private:
	int first;
	int second;

	

public:
	// default
	Test()  {
		this->first = 0;
		this->second = 0;
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

		this->first = first;
		this->second = second;
		
	}

	//Set first
	void set_values(int first, int second);

	int get_first() {
		return this->first;
	}

	int get_second() {
		return this->second;
	}

	void print_fields();

	bool check(int x);

	Test operator + (Test second);

	Test operator + (int second);

	friend Test operator + (int, Test&);

};






