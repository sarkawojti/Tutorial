#pragma once

#include <string>

class ILevelLogger
{
public:
    virtual void info(const std::string&) const = 0;
    virtual void error(const std::string&) const = 0;
    virtual void warning(const std::string&) const = 0;
    virtual void debug(const std::string&) const = 0;
};
