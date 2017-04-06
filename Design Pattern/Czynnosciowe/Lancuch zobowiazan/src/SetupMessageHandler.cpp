
#include "../inc/SetupMessageHandler.h"

#include <iostream>

void SetupMessageHandler::handle(const Message& msg) const
{
    if(MessageId::id_setup == msg.id)
    {
        std::cout << "Handle " << msg << "." << std::endl;
        return;
    }
    if(next)
    {
        next->handle(msg);
    }

}
