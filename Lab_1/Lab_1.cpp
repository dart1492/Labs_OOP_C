
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Test.h"

void change_vector(std::vector <Test> &objects_vect) {
    int y;
    std::cout << "Choose the element of the vector:" << std::endl;
    std::cin >> y;
    std::cout << "Current values : "; objects_vect[y].print_fields();
    

    std::cout << "if you want to change values press 1, to test the method press 2:" << std::endl;
    int z;
    std::cin >> z;
    if (z == 1) {
        std::cout << "      Enter new values:" << std::endl;
        int new_first, new_second;
        std::cin >> new_first >> new_second;
        objects_vect[y].set_first(new_first);
        objects_vect[y].set_second(new_second);
        std::cout << "      New values:"; objects_vect[y].print_fields();
    }
    else if (z == 2) {
        int check_value;
        std::cout << "      Insert x value:" << std::endl;
        std::cin >> check_value;
        if (objects_vect[y].check(check_value)) {
            std::cout << "      This value is in the range!" << std::endl;
        }
        else {
            std::cout << "      Wrong value!" << std::endl;
        }

    }
    else {
        return;
    }

    std::cout << "Press 1 to end the function, press to 2 to run again" << std::endl;
    std::cin >> z;

    if (z == 1) {
        return;
    }
    else if (z == 2) {
        change_vector(objects_vect);
    }

 }

int main()
{
    srand(time(0));
    
    Test first;

    Test sec(0, 10);

    std::cout << "Default constructor:"; first.print_fields();
    std::cout << "Parametrized constructor:"; sec.print_fields();

    int x = 5;
    if (sec.check(x)) {
        std::cout << "X = " << x << " belongs to the Second object" << std::endl;
    }

    std::vector  <Test> objects_vect;

    int first_arg;
    int second_arg;

    std::cout << "Vector, filled with randomly generated values:" << std::endl;
    for (int i = 0; i < 10; i++) {
        
        first_arg = rand() % 100;
        second_arg = first_arg + (rand() % 100);


        Test new_val(first_arg, second_arg);
        objects_vect.push_back(new_val);
    }

    for (int i = 0; i < objects_vect.size(); i++) {
        objects_vect[i].print_fields();
    }

    int y;
    std::cout << "You want to change this vector? 1 - Yes" << std::endl;
    std::cin >> y;

    if (y) {
        change_vector(objects_vect); 
    }
    

    Test rad_1(3, 9);
    Test rad_2(5, 16);

    std::cout << "rad_1:"; rad_1.print_fields();
    std::cout << "rad_2:"; rad_2.print_fields();

    std::cout << "rad_1 + rad_2:"; (rad_1 + rad_2).print_fields(); // obj + obj
        
    std::cout << "rad_1 + int:"; (rad_1 + 5).print_fields(); // obj + int     

    std::cout << "int + rad_2:"; (5 + rad_2).print_fields(); // int + obj

    std::cout << "prefix increment:"; ++rad_1; // postfix increment
    rad_1.print_fields();

    std::cout << "postfix increment:"; rad_1++; // suffix increment
    rad_1.print_fields();

}


