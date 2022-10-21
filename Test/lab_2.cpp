#include <iostream>
#include <string>
#include "test.h"
using namespace std;

void F() {
	const int N = 5, M = 3, K = 8;
	test A("A", N), B("B", M);
	cout << "input 5 elements: ";
	cin >> A;
	cout << "input 3 elements: ";
	cin >> B;
	cout << endl << A << endl << B << endl; 
	test C = A;
	test D("D", K);
	D = A - B;

	cout << endl << "massiv A: " << A << "\nmassive B: " << B << "\nmassive C: " << C << "\nmassive D: " << D;

	cout << "\ncehcking next function for A: " << A.next();

	cout << "\nchecking next().next() function for B: " << B.next().next();
}

int main()
{
	F();
}
