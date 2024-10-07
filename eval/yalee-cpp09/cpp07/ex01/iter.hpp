#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename FuncP> void iter(T *adr, T len, FuncP func)
{
    for (int i = 0; i < len; i++)
    {
        func(adr[i]);
    }
}

#endif