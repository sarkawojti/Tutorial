#pragma once

#include "Driver.h"

class ICar
{
public:
    virtual void drive(const Driver& driver) const = 0;
    virtual ~ICar() = default;
};
