#pragma once

#include "MessageId.h"
#include <iostream>

struct Message
{
    MessageId id;
};

std::ostream& operator<<(std::ostream&, const Message&);
