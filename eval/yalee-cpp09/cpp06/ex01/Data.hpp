#ifndef DATA_HPP
#define DATA_HPP

#include <string>

using std::string;

class Data {
private:
    string name;
public:
    Data();
    ~Data();
    void setName(string const name);
    string getName() const;
};

#endif