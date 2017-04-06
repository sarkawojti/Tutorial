
#include "../inc/InitMessageHandler.h"
#include <iostream>


void InitMessageHandler::handle(const Message& msg) const
{
    if(MessageId::id_init == msg.id)
    {
        std::cout << "Handle " << msg << "." << std::endl;
        return;
    }
    if(next)
    {
        next->handle(msg);
    }

}
