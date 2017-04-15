
#pragma once

#include "ReaderDecorator.h"
#include <iostream>
#include <memory>

class UpperReader : public ReaderDecorator
{
public:
    UpperReader(std::shared_ptr<IReader> & reader): ReaderDecorator(reader){}
    std::string read() override;
};
