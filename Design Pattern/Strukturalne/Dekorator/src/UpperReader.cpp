#include "../inc/UpperReader.h"
#include <algorithm>

UpperReader::UpperReader(std::shared_ptr<IReader>& _reader):
    reader(_reader)
{
}

std::string UpperReader::read()
{
    std::string result = reader->read();
    std::transform(result.begin(), result.end(),result.begin(), ::toupper);
    return result;
}



