#include "Easyfind.hpp"
# include <deque>

// const char *NotFoundException::what() const throw()
// {
// 	return "Huh? What is that?";
// }

template<typename Container>
void printArr( Container &cont)
{
    typename Container::iterator ptr;

    for (ptr = cont.begin(); ptr != cont.end(); ptr++)
        std::cout << *ptr << " ";
    std::cout << std::endl;
}

void test_deque(void)
{
	try
	{
		std::deque <int> arr;
		arr.push_back(3);
		arr.push_back(2);
		arr.push_back(1);
		arr.push_back(4);
		// easyFind(arr, 3);
		decltype(arr)::iterator iter = easyfind(arr, 3);
		std::cout << std::distance(arr.begin(), iter) << std::endl;
		iter = easyfind(arr, 4);
		std::cout << std::distance(arr.begin(), iter) << std::endl;
		printArr(arr);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error:\t" << e.what() << std::endl;
	}
}

#include <unistd.h>
#include <iterator>
void test_vector()
{
	try
	{
		std::vector <int> arr;
		arr.push_back(3);
		arr.push_back(2);
		arr.push_back(1);
		arr.push_back(1);
		arr.push_back(4);
		// easyFind(arr, 3);
		decltype(arr)::iterator iter = easyfind(arr, 3);
		std::cout << std::distance(arr.begin(), iter) << std::endl;
		iter = easyfind(arr, 4);
		std::cout << std::distance(arr.begin(), iter) << std::endl;
		printArr(arr);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error:\t" << e.what() << std::endl;
	}
}

int main()
{
	std::cout << std::uppercase << "test_vector" << std::endl;
	test_vector();
	std::cout << std::uppercase << "test_deque" << std::endl;
	test_deque();
}

