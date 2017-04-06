#pragma once

#include "IMessageHandler.h"

class MessageHandler : public IMessageHandler
{
public:
    void add_next(const std::shared_ptr<IMessageHandler>&) override;
protected:
    std::shared_ptr<IMessageHandler> next = nullptr;
};
