
#include "../inc/MessageHandler.h"

void MessageHandler::add_next(const std::shared_ptr<IMessageHandler>& handler)
{
    next = handler;
}
