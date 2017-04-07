#pragma once

#include "IATM.h"
#include "MoneyValue.h"

#include <memory>

class IHandleMoney : public IATM
{
public:
    virtual ~IHandleMoney() = default;

    virtual void add_next(const std::shared_ptr<IHandleMoney>&) = 0;
};
