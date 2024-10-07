#include "Array.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    // int a[10] = {1};
    // cout << a[0] << endl;
    // cout << a[1] << endl;
    // cout << a[2] << endl;
    try
    {
        Array<string> str_arr(10);
        str_arr[0] = "69";
        cout << str_arr[0] << endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "error: " << e.what() << endl;
    }
}