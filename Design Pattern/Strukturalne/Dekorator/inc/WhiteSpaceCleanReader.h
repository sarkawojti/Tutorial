#pragma once

#include "IReader.h"
#include <iostream>
#include <memory>

class WhiteSpaceCleanReader : public IReader
{
public:
    WhiteSpaceCleanReader(std::shared_ptr<IReader> &);
    std::string read() override;
private:
    std::shared_ptr<IReader> reader;
};
