#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// void displayStats(ClapTrap a, ClapTrap b, ClapTrap c)
// {
//     cout << a.getName() << endl;
//     cout << "HP: " << a.getHp() << endl;
//     cout << "EP: " << a.getEp() << endl << endl;
    
//     cout << b.getName() << endl;
//     cout << "HP: " << b.getHp() << endl;
//     cout << "EP: " << b.getEp() << endl << endl;
    
//     cout << c.getName() << endl;
//     cout << "HP: " << c.getHp() << endl;
//     cout << "EP: " << c.getEp() << endl << endl;
    
//     cout << "1 to attack, 2 to heal" << endl;
// }

// int main()
// {
//     ClapTrap block("block");
//     ClapTrap slob("slob");
//     string input;
//     cout << "enter yout name: " << endl;
//     getline(cin, input);
//     cout << "You are now a ClapTrap named " << input << endl;
//     ClapTrap player(input);
//     while (true)
//     {
//         displayStats(block, slob, player);
//         getline(cin, input);
//         if (input == "1")
//         {
//             player.attack(slob.getName());
//             slob.takeDamage(player.getAtk());
//         }
//         else if (input == "2")
//         {
//             player.beRepaired(1);
//         }
//         else
//             continue;
//     }
// }

int main()
{
	std::string en = "enemy";
	ScavTrap S("Scav");
	ClapTrap C("Clap");

	S.attack("Clap");
	C.takeDamage(5);
	C.attack("Scav");
	S.guardgate();
	C.beRepaired(2);
}