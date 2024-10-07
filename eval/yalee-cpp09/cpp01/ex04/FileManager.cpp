#include "FileManager.hpp"

using namespace std;

FileManager::FileManager(char *fn, char *s1, char *s2)
{
    cout << "constructor for FileManager" << endl;
    FileManager::fileName.assign(fn);
    FileManager::s1.assign(s1);
    FileManager::s2.assign(s2);
    FileManager::infile.open(fn);
    FileManager::outfile.open(strcat(fn, ".replace"));
}

FileManager::~FileManager()
{
    cout << "destrutor for FileManager" << endl;
}

string FileManager::getFilename()
{
    return (FileManager::fileName);
}

string FileManager::getS1()
{
    return (FileManager::s1);
}

string FileManager::getS2()
{
    return (FileManager::s2);
}
