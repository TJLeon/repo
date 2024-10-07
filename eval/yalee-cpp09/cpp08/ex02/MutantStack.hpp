#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    MutantStack() : std::stack<T, Container>() {}
    MutantStack(const MutantStack &stack) : std::stack<T, Container>(stack) {}
    MutantStack& operator=(const MutantStack &stack)
    {
        if (this != &stack)
        {
            std::stack<T, Container>::operator=(stack);
        }
        return *this;
    }
    ~MutantStack() {}

    typedef typename Container::iterator iterator;
    iterator begin()
    {
        return std::stack<T, Container>::c.begin();
    }
    iterator end()
    {
        return std::stack<T, Container>::c.end();
    }
};

#endif