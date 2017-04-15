#include "../inc/ConsolLogger.h"

#include <iostream>

void ConsolLogger::log(const std::string& level, const std::string& msg) const
{
    std::cout << level << " : " << msg << std::endl;
}
