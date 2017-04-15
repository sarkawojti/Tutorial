
#include "../inc/LevelFileLogger.h"

void LevelFileLogger::error(const std::string& msg) const
{
    log("Error", msg);
}

void LevelFileLogger::warning(const std::string& msg) const
{
    log("Warning", msg);
}

void LevelFileLogger::debug(const std::string& msg) const
{
    log("Debug", msg);
}

void LevelFileLogger::info(const std::string& msg) const
{
    log("Info", msg);
}

LevelFileLogger::LevelFileLogger(const std::string& file_name):
    FileLogger(file_name)
{
}
