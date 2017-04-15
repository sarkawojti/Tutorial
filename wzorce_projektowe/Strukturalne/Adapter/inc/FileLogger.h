#pragma once

#include "ILogger.h"

#include <fstream>

class FileLogger : public ILogger
{
    std::string _file_name;
    std::ofstream _file;
public:
    FileLogger(const std::string&);
    void log(const std::string&, const std::string&) override;
    ~FileLogger();
};
