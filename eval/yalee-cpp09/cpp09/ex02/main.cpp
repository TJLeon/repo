#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }
    PmergeMe pm(argv[1]);
    pm.mergeVector();
    pm.mergeDeque();
    return 0;
}