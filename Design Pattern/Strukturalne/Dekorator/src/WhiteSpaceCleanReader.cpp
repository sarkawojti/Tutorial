#include "../inc/WhiteSpaceCleanReader.h"
#include <algorithm>

WhiteSpaceCleanReader::WhiteSpaceCleanReader(std::shared_ptr<IReader>& _reader):
    reader(_reader)
{
}

std::string WhiteSpaceCleanReader::read()
{
    std::string result = reader->read();
    result.erase(std::remove_if(result.begin(),
                                result.end(),
                              [](char x){return std::isspace(x);}),
                result.end());
    return result;
}


