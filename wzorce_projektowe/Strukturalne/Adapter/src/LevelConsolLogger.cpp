#include "../inc/LevelConsolLogger.h"

void LevelConsolLogger::error(const std::string& msg)
{
    log("Error", msg);
}

void LevelConsolLogger::warning(const std::string& msg)
{
    log("Warning", msg);
}

void LevelConsolLogger::debug(const std::string& msg)
{
    log("Debug", msg);
}

void LevelConsolLogger::info(const std::string& msg)
{
    log("Info", msg);
}
