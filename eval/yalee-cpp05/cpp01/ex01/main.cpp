#include "Zombie.hpp"

int main()
{
    string input;
    int i;
    cout << "Enter number of zombies to create: ";
    getline(cin, input);
    stringstream ss(input);
    ss >> i;
    Zombie* horde = zombieHorde(i, "qiqi");
    cout << "Now lets try accesing them. " << endl << "(press enter to continue)" << endl;
    getline(cin, input);
    for (int x = 0; x < i; x++)
        horde[x].announce();
    delete [] horde;
}