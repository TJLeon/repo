#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Zombie{
public:
    Zombie();
    Zombie(string name);
    ~Zombie();
    void announce();
    void setName(string name);
private:
    string name;
};

Zombie* zombieHorde(int N, string name);