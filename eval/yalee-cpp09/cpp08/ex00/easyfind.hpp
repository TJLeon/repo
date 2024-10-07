#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <iostream>

class NotFoundException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Element not found";
    }
};

template <typename T> int easyFind(T &container, int value)
{
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); it++)
    {
        if (*it == value)
        {
            std::cout << "Found at: " << *it << std::endl;
            return *it;
        }
    }
    throw NotFoundException();
}

#endif