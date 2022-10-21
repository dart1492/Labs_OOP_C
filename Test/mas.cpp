#include "mas.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

//task 1.1.1
mas::mas(string Name, int Size)
{
    name = Name;
    cout << "Constructor WITH parameters is working now for " << name << "!!!" << endl;
    size = Size;
    Mas = new int[size];
    if (!Mas)
    {
        cout << "Memory error!!!" << endl;
        exit(0);
    }
    for (int i = 0; i < size; i++)
    {
        Mas[i] = 0;
    }
}

mas::mas()
{
    name = "array";
    cout << "Constructor WITHOUT parameters is working now for " << name << "!!!" << endl;
    size = 1;
    Mas = new int[size];
    if (!Mas)
    {
        cout << "Memory error!!!" << endl;
        exit(0);
    }

    for (int i = 0; i < size; i++)
    {
        Mas[i] = 0;
    }
}

//task 1.1.2
mas::~mas()
{
    if (!Mas)
    {
        cout << "Memory error!!!" << endl;
        exit(0);
    }
    cout << "Destructor is working now for " << name << "!!!" << endl;
    delete[] Mas;
    size = 0;
    *Mas = NULL;
}

//task 1.1.3
int& mas::operator[](int i)
{
    if (i < 0 or i >= size)
    {
        cout << "A wrong index!!!" << endl;
        exit(0);
    }
    return Mas[i];
}

//task 1.1.4
mas mas::operator*(mas array)
{
    vector <int> arr;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < array.size; j++)
        {
            if (Mas[i] == array[j])
            {
                arr.push_back(Mas[i]);
            }
        }
    }

    mas peretyn("Intersection of arrays", arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        peretyn[i] = arr[i];
    }
    return peretyn;
}

//task 1.4
mas::mas(const mas& array)
{
    Mas = new int[array.size];
    size = array.size;
    name = array.name + " copy";
    for (int i = 0; i < size; i++)
    {
        Mas[i] = array.Mas[i];
    }
    cout << "Copy of " << array.name << endl;
}

//task 2
mas& mas::operator=(const mas array)
{
    cout << "Appropriation is working now for " << array.name << "!!!" << endl;
    if (this == &array)
        return *this;
    size = array.size;
    name = array.name;
    for (int i = 0; i < size; i++)
    {
        Mas[i] = array.Mas[i];
    }
    return *this;
}

//task 4
mas& mas::next()
{
    for (int i = 0; i < size; i++)
    {
        Mas[i] += 1;
    }
    return*this;
}

//task 3

istream& operator>>(istream& stream, mas& obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        stream >> obj[i];
    }
    return stream;
}

ostream& operator<<(ostream& stream, mas& obj)
{
    stream << "A name of the array: " << obj.name << endl;
    stream << "A size of the array: " << obj.size << endl;
    stream << "Elements of the array: " << endl;
    for (int i = 0; i < obj.size; i++)
    {
        stream << obj[i] << setw(5);
    }
    stream << endl;
    return stream;
}
