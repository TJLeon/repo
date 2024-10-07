#include "BitcoinExchange.hpp"

namespace {
bool isNumber(const std::string& str) {
    std::stringstream ss(str);
    double num;  // Or use int, float, etc. depending on your needs
    ss >> num;
    return !ss.fail() && ss.eof(); // Check for successful extraction and end of stream
}

bool isValidDate(const std::string& dateStr) {
    // Expected format: YYYY-MM-DD
    // Expected format: YYYY-MM-DD
    int year, month, day;

    std::istringstream ss(dateStr);

    // Extract year using the first '-' delimiter
    std::string yearStr;
    std::getline(ss, yearStr, '-');
    year = atoi(yearStr.c_str()); // Convert string to integer

    // Extract month using the second '-' delimiter
    std::string monthStr;
    std::getline(ss, monthStr, '-');
    month = atoi(monthStr.c_str());

    // Extract day (remaining part)
    ss >> day; 

    // Basic checks for valid month and day ranges
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    // Additional checks for months with fewer than 31 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    // February: check for leap year
    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > 29 || (day == 29 && !isLeapYear)) {
            return false;
        }
    }

    return true; // Date is valid
}
}

BitcoinExchange::BitcoinExchange()
{
    ifstream data("data.csv");
    string line;
    getline(data, line);
    while (getline(data, line))
    {
        BitcoinExchange::db.insert(pair<string, double>(line.substr(0, line.find(',')), stod(line.substr(line.find(',') + 1))));
    }
    // map<string, double>::iterator it = db.begin();
    // while (it != db.end())
    // {
    //     cout << it->first << " " << it->second << endl;
    //     it++;
    // }
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::printResult(const string &filename)
{
    string line;
    ifstream queryFile(filename);
    getline(queryFile, line);
    while (getline(queryFile, line))
    {
        string date = line.substr(0, line.find(' '));
        if (!isValidDate(date))
        {
            cout << "invalid date!" << endl;
            continue;
        }
        if (line[date.size() + 1] != '|' || line[date.size() + 2] != ' ')
        {
            cout << "invalid format!" << endl;
            continue;  
        }
        string amount = line.substr((date.size() + 3));
        if (!isNumber(amount) || stod(amount) > 214783648 || stod(amount) < 0)
        {
            cout << "invalid amount!" << endl;
            continue;
        }
        if (db.find(date) == db.end())
            cout << date << " => " << amount << " = " << "no data" << endl;
        else
            cout << date << " => " << amount << " = " << (stod(amount) * db.find(date)->second) << endl;
    }
}