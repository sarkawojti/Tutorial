#pragma once

#include "IReader.h"
#include <iostream>
#include <memory>

class UpperReader : public IReader
{
public:
    UpperReader(std::shared_ptr<IReader> &);
    std::string read() override;
private:
    std::shared_ptr<IReader> reader;
};

