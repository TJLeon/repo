#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include "Data.hpp"

class Data;

class Serialize {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif