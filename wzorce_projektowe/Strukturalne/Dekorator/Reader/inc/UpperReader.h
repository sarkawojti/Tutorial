
#pragma once

#include "ReaderDecorator.h"
#include <iostream>
#include <memory>

class UpperReader : public ReaderDecorator
{
public:
    UpperReader(const std::shared_ptr<IReader> & reader = nullptr): ReaderDecorator(reader){}
    std::string read() override;
};
