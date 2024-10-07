#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iterator>
# include <vector>

// template <typename T>
// T easyFind(T &container, int integer)
// {
// 	typename T::iterator ptr;

// 	for (ptr = container.begin(); ptr < container.end(), ptr++)
// 	{
// 		if (*ptr == integer)
// 			return (static_cast<T>(*ptr));
// 	};
// 	throw(NotFoundException());
// };
// class NotFoundException : public std::exception
// {
// 	public:
// 		virtual const char* what() const throw();
// };

template <typename T>
typename T::iterator easyfind(T &container, const int integer)
{
    typename T::iterator ptr;

    for (ptr = container.begin(); ptr != container.end(); ++ptr) // Use '!=' to compare iterators
    {
        if (*ptr == integer) // Compare the element pointed to by 'ptr' with 'integer'
            return ptr;
    }
	throw std::out_of_range("Huh? Element not found in container.");
}

// template <typename T>
// typename T::iterator easyfind(T &container, const int integer)
// {
//     typename T::iterator ptr;

//     for (ptr = container.begin(); ptr != container.end(); ++ptr) // Use '!=' to compare iterators
//     {
//         if (*ptr == integer) // Compare the element pointed to by 'ptr' with 'integer'
//             return ptr;
//     }
// 	throw NotFoundException();
// }



#endif