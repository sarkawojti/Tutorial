
#pragma once

#include "ILevelLogger.h"
#include "FileLogger.h"

class LevelFileLogger : public ILevelLogger, private FileLogger
{
public:
    LevelFileLogger(const std::string&);

    void info(const std::string&) override;
    void error(const std::string&) override;
    void warning(const std::string&) override;
    void debug(const std::string&) override;
};
