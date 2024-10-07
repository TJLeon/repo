#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class FileManager{
public:
    FileManager(char *fn, char *s1, char *s2);
    ~FileManager();
    string getFilename();
    string getS1();
    string getS2();
    ifstream infile;
    ofstream outfile;
private:
    string fileName;
    string s1;
    string s2;
};

#endif