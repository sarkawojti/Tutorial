
#include "../inc/LevelFileLogger.h"

void LevelFileLogger::error(const std::string& msg)
{
    log("Error", msg);
}

void LevelFileLogger::warning(const std::string& msg)
{
    log("Warning", msg);
}

void LevelFileLogger::debug(const std::string& msg)
{
    log("Debug", msg);
}

void LevelFileLogger::info(const std::string& msg)
{
    log("Info", msg);
}

LevelFileLogger::LevelFileLogger(const std::string& file_name):
    FileLogger(file_name)
{
}
