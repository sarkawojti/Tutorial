
#pragma once

#include "ReaderDecorator.h"
#include <iostream>
#include <memory>

class WhiteSpaceCleanReader : public ReaderDecorator
{
public:
    WhiteSpaceCleanReader(std::shared_ptr<IReader> & reader): ReaderDecorator(reader){}
    std::string read() override;
};
