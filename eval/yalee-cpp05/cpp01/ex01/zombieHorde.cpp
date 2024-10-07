#include "Zombie.hpp"

Zombie* zombieHorde(int N, string name)
{
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        stringstream num;
        string temp = name;
        num << i;
        string sNum = num.str();
        temp.append(sNum);
        horde[i].setName(temp);
    }

    return horde;
}