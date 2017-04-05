#pragma once

#include "IReader.h"

class FileReader : public IReader
{
public:
    FileReader(const std::string&);
    std::string read() override;
private:
    std::string file_name;
};
