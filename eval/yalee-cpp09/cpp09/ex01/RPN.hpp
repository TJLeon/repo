#pragma once

#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::cout;
using std::endl;
using std::string;

class RPN
{
private:
    stack<int> s;
    string params;
public:
    RPN();
    RPN(const string input);
    ~RPN();
    void calculate();
};
