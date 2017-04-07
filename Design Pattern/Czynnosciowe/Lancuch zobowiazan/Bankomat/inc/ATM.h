#pragma once

#include "IATM.h"
#include "IHandleMoney.h"
#include "Handle500Money.h"

class ATM  : public IATM
{
public:
    ATM();
    void update_money_of(const MoneyValue&, unsigned) override;
    unsigned total_money() const override;
    bool get_money(unsigned) override;

private:
    std::shared_ptr<IHandleMoney> _handler = std::make_shared<Handle500Money>();
};
