#pragma  once

#include "ILogger.h"

class ConsolLogger : public ILogger
{
public:
    void log(const std::string&, const std::string&) override;
};
