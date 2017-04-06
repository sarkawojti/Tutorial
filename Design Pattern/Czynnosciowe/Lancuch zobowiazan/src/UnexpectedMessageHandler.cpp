
#include "../inc/UnexpectedMessageHandler.h"

void UnexpectedMessageHandler::handle(const Message& msg) const
{
    std::cout << "Handle unexpected " << msg << "." << std::endl;
}
