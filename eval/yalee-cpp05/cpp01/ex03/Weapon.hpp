#ifndef WEAPON_H
#define WEAPON_H
#include <string>

using namespace std;

class Weapon{
public:
    Weapon();
    Weapon(string type);
    ~Weapon();
    const string& getType();
    void setType(string type);
private:
    string type;
};

#endif