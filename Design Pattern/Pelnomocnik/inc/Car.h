#pragma once

#include "ICar.h"

class Car : public ICar
{

public:
    void drive(const Driver& driver) const override {}
};
