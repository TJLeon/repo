#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const string input)
{
    params = input;
}

RPN::~RPN()
{
}

void RPN::calculate()
{
    for (int i = 0; params[i] ; i++)
    {
        if (params[i] == ' ')
            continue;
        if (params[i] <= '0' && params[i] >= '9')
        {
            cout << "Error: Invalid character" << endl;
            return;
        }
        if (params[i] == '+' || params[i] == '-' || params[i] == '*' || params[i] == '/')
        {
            if (s.size() < 2)
            {
                cout << "Error: Not enough operands" << endl;
                return;
            }
            int a = s.top();
            cout << a << " is popped" << endl;
            s.pop();
            int b = s.top();
            cout << b << " is popped" << endl;
            s.pop();
            cout << "calculate " << a << " and " << b << " with " << params[i] << endl;
            if (params[i] == '+')
            {
                s.push((a) + (b));
                cout << "pushed " << (a) + (b) << endl;
            }
            else if (params[i] == '-')
            {
                s.push((b) - (a));
                cout << "pushed " << (a) - (b) << endl;
            }
            else if (params[i] == '*')
            {
                s.push((a) * (b));
                cout << "pushed " << (a) * (b) << endl;
            }
            else if (params[i] == '/')
            {
                s.push((b) / (a));
                cout << "pushed " << (a) / (b) << endl;
            }
        }
        else
        {
            cout << "pushed " << params[i] << endl;
            s.push(params[i] - '0');
        }
    }
    cout << "Result:" << endl;
    cout << (s.top()) << endl;
    s.pop();
}