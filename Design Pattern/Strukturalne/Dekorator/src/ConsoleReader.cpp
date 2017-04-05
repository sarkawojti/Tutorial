#include "../inc/ConsoleReader.h"

ConsoleReader::ConsoleReader(const std::string& _command_name):
    command_name(_command_name)
{
}

std::string ConsoleReader::read()
{
    std::string result;
    std::cout << command_name;
    std::getline(std::cin, result);

    return result;
}
