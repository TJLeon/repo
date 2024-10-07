#ifndef TARGETDIRECTORYOBJ_HPP
#define TARGETDIRECTORYOBJ_HPP

#include <sys/stat.h>
#include <string>
#include <exception>
#include <iostream>

using std::string;
using std::exception;
using std::cout;
using std::endl;

class DirectoryNotFoundException : public exception
{
public:
    const char *what() const throw();
};

class TargetDirectoryObj
{
private:
    const string path;
public:
    TargetDirectoryObj(const string & path);
    ~TargetDirectoryObj();
    string getPath() const;
};
#endif