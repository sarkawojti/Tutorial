#pragma once

#include "IReader.h"
#include <iostream>

class ConsoleReader : public IReader
{
public:
    ConsoleReader(const std::string&);
    std::string read() override;
private:
    std::string command_name;
};
