#pragma once

#include "IReader.h"
#include <memory>

class ReaderDecorator : public IReader
{
public:
    ReaderDecorator(const std::shared_ptr<IReader>& _reader): reader(_reader){}

    void set_reader(const std::shared_ptr<IReader>& _reader)
    {
        reader = _reader;
    }
protected:
    std::shared_ptr<IReader> reader;
};
