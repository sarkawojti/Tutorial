
#include <iostream>

#include "../inc/Message.h"

std::ostream& operator<<(std::ostream &os, const Message& msg)
{
    os << "Message { id : " << (int)msg.id
       << "}";
    return os;
}
