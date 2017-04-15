#include "../inc/ConsolLogger.h"

#include <iostream>

void ConsolLogger::log(const std::string& level, const std::string& msg)
{
    std::cout << level << " : " << msg << std::endl;
}
