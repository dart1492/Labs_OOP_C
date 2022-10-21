
#include <iostream>
#include "Cus_arr.h"
#include <vector>

void F(void);
using namespace std;


int main()
{
    F();
}


void F(void) {
	
    Cus_arr A("A", 3);
	cin >> A;

	Cus_arr B("B", 0);
	cin >> B;
    
    std::cout << A; // print A elems 
    
    std::cout << B; // print B elems 
   
	Cus_arr C(A);
	std::cout << C;

    Cus_arr D("D", 4);
	D = A + B;
	std::cout << D;

	std::cout << D.next().next().next();
	
    
}

/*void F(void) {
    Клас_масив А(“A”, n), В(“B”, m);
    введення елементів масивів А та В
    Клас_масив С = А;
    Клас_масив D(“D”, k);
    D = А @ В; замість ‘@’ підставте свою операцію над масивами
    виведення масивів A, B, C, D
}*/

