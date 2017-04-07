#pragma once

#include "MoneyValue.h"

class IATM
{
public:
    virtual void update_money_of(const MoneyValue&, unsigned) = 0;
    virtual unsigned total_money() const = 0;
    virtual bool get_money(unsigned) = 0;
};
