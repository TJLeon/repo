#include "iter.hpp"
#include <iostream>

using std::cout;
using std::endl;

void plusOne(int &x)
{
    x++;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 5, 7, 8, 9, 0};
    ::iter(arr, 10, plusOne);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << endl;
}