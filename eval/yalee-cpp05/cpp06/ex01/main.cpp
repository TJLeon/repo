#include "Serialize.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data* data = new Data;
    std::cout << "data: " << data << std::endl;
    uintptr_t ptr = Serialize::serialize(data);
    std::cout << "data after serialize: " << ptr << std::endl;
    data = Serialize::deserialize(ptr);
    std::cout << "data after reserialize: " << data << std::endl;
}