#include "Harl.hpp"

Harl::Harl()
{
    cout << "Harl created" << endl;
}

Harl::~Harl()
{
    cout << "Harl destroyed" << endl;
}

// void Harl::complain(string level)
// {
//     map<string, function<void(Harl*)>>funcmap = {
//         {"debug", &Harl::debug},
//         {"info", &Harl::info},
//         {"warning", &Harl::warning},
//         {"error", &Harl::error}
//     };
// }
void Harl::debug(void)
{
    cout << "[DEBUG] Harl need friend." << endl;
}

void Harl::info(void)
{
    cout << "[INFO] Harl need friend because Harl lonely." << endl;
}

void Harl::warning(void)
{
    cout << "[WARNING] Harl need friend, to make Harl feel alive. If Harl feel dead, Harl shoot up skool. " << endl;
}

void Harl::error(void)
{
    cout << "[ERROR] HAHAHAHA Harl shook skool!!!!" << endl;
}

void Harl::complain(string level)
{
	void (Harl::*funct[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	string arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int x = 0;
	while (x < 4 && arr[x].compare(level))
		x++;
	if(x < 4)
		(this->*funct[x++])();
	else
		cout << "[ Probably complaining about insignificant problems ]" << endl;
}