
#pragma once

#include "ReaderDecorator.h"
#include <iostream>
#include <memory>

class WhiteSpaceCleanReader : public ReaderDecorator
{
public:
    WhiteSpaceCleanReader(const std::shared_ptr<IReader> & reader = nullptr): ReaderDecorator(reader){}
    std::string read() override;
};
