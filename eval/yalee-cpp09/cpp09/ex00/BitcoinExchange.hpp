#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::ifstream;
using std::map;
using std::pair;
using std::cout;
using std::endl;


class BitcoinExchange
{
private:
    map<string, double> db;
public:
    BitcoinExchange();
    ~BitcoinExchange();
    void printResult(const string &filename);
};