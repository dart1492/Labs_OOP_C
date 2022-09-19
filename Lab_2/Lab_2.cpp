
#include <iostream>
#include "Cus_arr.h"
#include <vector>

void F(void);
using namespace std;

class SmartArray {

	string name_mass;
	size_t data_size = 0;
	int* data = nullptr;

	void create_array(size_t size) {
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = 0;
		}
	}

public:

	void Set_name_mass(string name) {
		name_mass = move(name);
	}

	void Set_data_size(size_t size) {
		data_size = size;
	}


	void Set_data(int* data) {
		this->data = data;
	}

	void Set_data(vector<int> _data) {
		this->data = new int[_data.size()];
		this->data_size = _data.size();
		for (size_t i = 0; i < _data.size(); i++) {
			this->data[i] = _data[i];
		}
	}

	string Get_name_mass() {
		return name_mass;
	}

	size_t Get_data_size() const {
		return data_size;
	}

	int* Get_data() {
		return data;
	}

	SmartArray(string name, size_t size) {
		name_mass = move(name);
		data_size = size;
		cout << "Param constructor, " << this << endl;
		create_array(size);
	}

	SmartArray() {
		name_mass = "default";
		data_size = 5;
		create_array(data_size);
		cout << "Default constructor, " << this << endl;
	}

	SmartArray(SmartArray& obj2) {
		name_mass = obj2.Get_name_mass();
		data_size = obj2.Get_data_size();
		create_array(data_size);
		for (int i = 0; i < data_size; i++) {
			data[i] = obj2[i];
		}
		cout << "Copy constructor, " << this << "(copied " << &obj2 << ")" << endl;
	}

	~SmartArray() {
		if (data != nullptr) {
			delete[] data;
			cout << "Destructor, " << this << endl;
		}
	}

	int& operator[](int index) {
		return data[index];
	}

	SmartArray& operator=(const SmartArray& CopArray) {
		this->data_size = CopArray.data_size;
		for (int i = 0; i < this->data_size; i++) {
			this->data[i] = CopArray.data[i];
		}
		cout << "Cop, " << this << endl;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const SmartArray& point);

	SmartArray& operator-(SmartArray& c1) {
		vector<int> Result;
		int* second_array = c1.Get_data();
		size_t second_array_size = c1.Get_data_size();
		bool* deleted_elements = new bool[second_array_size];
		for (int i = 0; i < second_array_size; i++) {
			deleted_elements[i] = false;
		}
		for (int i = 0; i < this->Get_data_size(); i++) {
			bool need_to_add = true;
			for (int j = 0; j < second_array_size; j++) {
				if (this->data[i] == second_array[j] && !deleted_elements[j]) {
					need_to_add = false;
					deleted_elements[j] = true;
					break;
				}
			}
			if (need_to_add) {
				Result.push_back(this->data[i]);
			}
		}
		auto* Result_ = new SmartArray("", Result.size());
		Result_->Set_data(Result);
		delete[] deleted_elements;
		return *Result_;
	}

	auto next() {
		SmartArray NewArray = *this;
		for (int i = 0; i < this->data_size; ++i) {
			NewArray.data[i]++;
		}
		return NewArray;
	}

	void Print_array() const {
		cout << *this;
	}
};

ostream& operator<<(ostream& stream, const SmartArray& obj) {
	stream << obj.name_mass << "\n" << obj.data_size << endl;
	for (int i = 0; i < obj.data_size; i++) {
		stream << obj.data[i] << " ";
	}
	stream << endl;
	return stream;
}

int main()
{
    
    

   
    F();
}


void F(void) {
	
    Cus_arr A("A", 3);
	cin >> A;

	Cus_arr B("B", 2);
	cin >> B;
    

    std::cout << A; // print A elems 
    
    std::cout << B; // print B elems 
   
	
	Cus_arr C(A);
	std::cout << C;

	Cus_arr D = A + B;
	std::cout << D;

	D = D.next().next().next();
	std::cout << D;
    

}

/*void F(void) {
    Клас_масив А(“A”, n), В(“B”, m);
    введення елементів масивів А та В
    Клас_масив С = А;
    Клас_масив D(“D”, k);
    D = А @ В; замість ‘@’ підставте свою операцію над масивами
    виведення масивів A, B, C, D
}*/

