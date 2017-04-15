#pragma once

#include <iostream>

class IReader
{
public:
    virtual std::string read() = 0;
    virtual ~IReader() = default;
};
