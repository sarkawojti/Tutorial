#pragma once

#include "IHandleMoney.h"

class HandleMoney : public IHandleMoney
{
public:
    void add_next(const std::shared_ptr<IHandleMoney>&) override;
    void update_money_of(const MoneyValue&, unsigned) override;
    unsigned total_money() const override;
    bool get_money(unsigned) override;

protected:
    std::shared_ptr<IHandleMoney> _next = nullptr;
    unsigned _num_of = 0;
    MoneyValue money_value;
};
