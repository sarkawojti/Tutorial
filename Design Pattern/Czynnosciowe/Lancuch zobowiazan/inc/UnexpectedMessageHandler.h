
#pragma once

#include "MessageHandler.h"

class UnexpectedMessageHandler : public MessageHandler
{
public:
    void handle(const Message&) const override;
};
