#pragma once

#include "ILogger.h"

#include <fstream>

class FileLogger : public ILogger
{
    std::string _file_name;
    mutable std::ofstream _file;
public:
    FileLogger(const std::string&);
    void log(const std::string&, const std::string&) const override;
    ~FileLogger();
};
