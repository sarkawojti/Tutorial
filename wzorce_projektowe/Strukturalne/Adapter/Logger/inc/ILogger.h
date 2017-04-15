#pragma once

#include <string>

class ILogger
{
public:
    virtual void log(const std::string&, const std::string&) const = 0;
};
