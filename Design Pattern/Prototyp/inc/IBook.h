
#include "ICloneable.h"

#pragma once

class IBook : public ICloneable
{
public:
    virtual std::string title() const = 0;


};
