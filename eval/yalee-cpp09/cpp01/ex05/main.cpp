#include "Harl.hpp"

int main()
{
    Harl harl;
    string input;
    while (true)
    {
        cout << "input: ";
        getline(cin, input);
        for (string::size_type i = 0; i < input.length(); ++i)
        {
            input[i] = toupper(input[i]);
        }
        harl.complain(input);

    }
}