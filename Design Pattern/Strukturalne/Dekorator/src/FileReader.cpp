#include "../inc/FileReader.h"

#include <fstream>

FileReader::FileReader(const std::string& _file_name):
    file_name(_file_name)
{
}

std::string FileReader::read()
{
    std::ifstream file;
    file.open(file_name.c_str());

    std::string result;
    while (not file.eof())
    {
        std::string tmp;
        std::getline(file, tmp);
        result += tmp;
    }
    file.close();

    return result;
}
