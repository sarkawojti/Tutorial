#pragma once

#include "ILevelLogger.h"
#include "ConsolLogger.h"

class LevelConsolLogger : public ILevelLogger, private ConsolLogger
{
public:
    void info(const std::string&) override;
    void error(const std::string&) override;
    void warning(const std::string&) override;
    void debug(const std::string&) override;
};
