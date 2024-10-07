#include "Serialize.hpp"

uintptr_t Serialize::serialize(Data* ptr)
{
    uintptr_t intPtr = reinterpret_cast<uintptr_t>(ptr);
    return intPtr;
}

Data* Serialize::deserialize(uintptr_t raw)
{
    Data* originalPtr = reinterpret_cast<Data*>(raw);
    return originalPtr;
}