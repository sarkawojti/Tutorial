
#pragma once

#include "MessageHandler.h"

class SetupMessageHandler : public MessageHandler
{
public:
    void handle(const Message&) const override;
};

