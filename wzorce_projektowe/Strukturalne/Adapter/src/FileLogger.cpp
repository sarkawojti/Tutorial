#include "../inc/FileLogger.h"

#include <iostream>

void FileLogger::log(const std::string& level, const std::string& msg) const
{
    if(not _file.is_open())
    {
        _file.open(_file_name.c_str(), std::ios_base::out | std::ios_base::app);
    }

    if(_file.good())
    {
        _file << level << " : " << msg << std::flush;
    }
}

FileLogger::FileLogger(const std::string& file_name)
    : _file_name(file_name)
{
}

FileLogger::~FileLogger()
{
    _file.close();
}
