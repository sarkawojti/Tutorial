
#include "../inc/LevelLogger.h"
#include "../inc/ILogger.h"

void LevelLogger::error(const std::string& msg) const
{
    _logger->log("Error", msg);
}

void LevelLogger::warning(const std::string& msg) const
{
    _logger->log("Warning", msg);
}

void LevelLogger::debug(const std::string& msg) const
{
    _logger->log("Debug", msg);
}

void LevelLogger::info(const std::string& msg) const
{
    _logger->log("Info", msg);
}

void LevelLogger::set_adaptee(const std::shared_ptr<ILogger>& logger)
{
    _logger = logger;
}

LevelLogger::LevelLogger(const std::shared_ptr<ILogger>& logger = nullptr):
    _logger(logger)
{
}
