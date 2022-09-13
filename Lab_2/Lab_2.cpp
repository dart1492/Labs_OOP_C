
#include <iostream>
#include "Cus_arr.h";
void F(void);

int main()
{
    F();
}


void F(void) {
    Cus_arr A("A", 3);

    Cus_arr B("B", 2);

    for (int i = 0; i < A.len(); i++) { // A fill
        A[i] = i + 1;
    }

    for (int i = 0; i < B.len(); i++) { // B fill
        B[i] = i + 10;
    }

    std::cout << A; // print A elems 
    
    
    std::cout << B; // print B elems 
   

    Cus_arr C = A;
    std::cout << C; 

    Cus_arr D("D", 6);
    D = A + B;
    std::cout << D; // print D elems 
   

}

/*void F(void) {
    Клас_масив А(“A”, n), В(“B”, m);
    введення елементів масивів А та В
    Клас_масив С = А;
    Клас_масив D(“D”, k);
    D = А @ В; замість ‘@’ підставте свою операцію над масивами
    виведення масивів A, B, C, D
}*/

