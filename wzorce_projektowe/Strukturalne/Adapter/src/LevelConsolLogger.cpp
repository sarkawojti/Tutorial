#include "../inc/LevelConsolLogger.h"

#include <iostream>

void LevelConsolLogger::error(const std::string& msg) const
{
    log("Error", msg);
}

void LevelConsolLogger::warning(const std::string& msg) const
{
    log("Warning", msg);
}

void LevelConsolLogger::debug(const std::string& msg) const
{
    log("Debug", msg);
}

void LevelConsolLogger::log(const std::string& level, const std::string& msg) const
{
    std::cout << "Level ";
    ConsolLogger::log(level, msg);
}

void LevelConsolLogger::info(const std::string& msg) const
{
    log("Info", msg);
}
