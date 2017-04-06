#pragma once

#include "MessageHandler.h"

class InitMessageHandler : public MessageHandler
{
public:
    void handle(const Message&) const override;
};
