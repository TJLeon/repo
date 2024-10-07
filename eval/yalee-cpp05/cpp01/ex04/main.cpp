#include <fstream>
#include "FileManager.hpp"

void debugg(FileManager& FM)
{
    cout << "debug: " << endl << FM.getFilename() << endl << FM.getS1() << endl << FM.getS2() << endl;
}

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        cout << "INPUT ERROR!" << endl;
        return (0);
    }
    FileManager FM(argv[1], argv[2], argv[3]);
    if (!FM.infile)
    {
        cout << "FILE ERROR!" << endl;
        return (0);
    }
    string line;
    while (getline(FM.infile, line))
    {
        size_t edpos = line.find(FM.getS1());
        while (edpos != line.npos)
        {
            if (edpos != line.npos)
            {
                line = line.substr(0, edpos) + FM.getS2() + line.substr(edpos + FM.getS1().length());
            }
            edpos = line.find(FM.getS1());
        }
        cout << line << endl;
        FM.outfile << line << endl;
    }
}