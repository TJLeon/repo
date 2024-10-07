#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "outOfRangeException.hpp"
#include <iostream>

class OutOfRange;
using std::string;
using std::cout;
using std::endl;

template <typename T> 
class Array
{
private:
    T *array;
    int size;
public:
    Array()
    {
        array = new T*;
    }
    Array(unsigned int n) : size(n)
    {
        array = new T[n];
    } 
    Array(const Array &arr) : size(arr.size)
    {
        array = new T[size];
        for (unsigned int i = 0; i < size; i++)
        {
            array[i] = arr.array[i];
            std::cout << array[i] << std::endl;
        }
    }
    Array& operator=(const Array &arr) 
    {
        if (this != &arr) 
        {
            delete[] array;
            size = arr.size;
            array = new T[size];
            for (unsigned int i = 0; i < size; i++)
            {
                array[i] = arr.array[i];
            }
        }
        return *this;
    }
    ~Array() 
    {
        delete[] array;
    }

    T& operator[](int index)
    {
        if (index > size)
        {
            throw OutOfRange();
        }
        return (array[index]);
    }

};

#endif