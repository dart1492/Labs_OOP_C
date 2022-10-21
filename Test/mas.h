#pragma once
#include <string>

class mas
{
    std::string name;
    int* Mas;
    int size;
public:

    //task 1.1.1
    mas(std::string Name, int Size);
    mas();

    //task 1.1.2
    ~mas();

    //task 1.1.3
    int& operator[](int i);

    //task 1.1.4
    mas operator*(mas array);

    //task 1.4
    mas(const mas& array);

    //task 2
    mas& operator= (const mas array);

    //task 3
    friend std::istream& operator>>(std::istream& stream, mas& obj);

    friend std::ostream& operator<<(std::ostream& stream, mas& obj);

    //task 4
    mas& next();
};

