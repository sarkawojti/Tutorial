#pragma once

#include "Message.h"
#include <memory>

class IMessageHandler
{
public:
    virtual ~IMessageHandler() = default;

    virtual void handle(const Message&) const = 0;
    virtual void add_next(const std::shared_ptr<IMessageHandler>&) = 0;
};
