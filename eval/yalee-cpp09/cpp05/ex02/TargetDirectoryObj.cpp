#include "TargetDirectoryObj.hpp"

const char *DirectoryNotFoundException::what() const throw()
{
    return "Directory does not exist!\n";
}

TargetDirectoryObj::TargetDirectoryObj(const string & path) : path(path)
{
    struct stat info;
    if (stat(path.c_str(), &info) != 0)
        throw DirectoryNotFoundException();
    else if (info.st_mode & S_IFDIR) 
        cout << "path is ok!" << endl;
    else
        throw DirectoryNotFoundException();
}

TargetDirectoryObj::~TargetDirectoryObj()
{
    // cout << "default target dir obj destructor" << endl;
}

string TargetDirectoryObj::getPath() const
{
    return path;
}