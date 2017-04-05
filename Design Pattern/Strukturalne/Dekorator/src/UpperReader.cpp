
#include "../inc/UpperReader.h"
#include <algorithm>

std::string UpperReader::read()
{
    std::string result = reader->read();
    std::transform(result.begin(), result.end(),result.begin(), ::toupper);
    return result;
}
