#pragma once

#include "ILevelLogger.h"

#include <memory>

class ILogger;

class LevelLogger : public ILevelLogger
{
    std::shared_ptr<ILogger> _logger;

public:
    LevelLogger(const std::shared_ptr<ILogger>&);

    void info(const std::string&) override;
    void error(const std::string&) override;
    void warning(const std::string&) override;
    void debug(const std::string&) override;
};
