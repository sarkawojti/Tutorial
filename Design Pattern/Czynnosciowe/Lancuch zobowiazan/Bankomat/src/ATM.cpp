#include "../inc/ATM.h"

#include "../inc/Handle200Money.h"
#include "../inc/Handle100Money.h"
#include "../inc/Handle50Money.h"
#include "../inc/Handle20Money.h"
#include "../inc/Handle10Money.h"

#include <iostream>

ATM::ATM()
{
    std::shared_ptr<HandleMoney> _handler20 = std::make_shared<Handle20Money>();
    _handler20->add_next(std::make_shared<Handle10Money>());

    std::shared_ptr<IHandleMoney> _handler50 = std::make_shared<Handle50Money>();
    _handler50->add_next(_handler20);

    std::shared_ptr<HandleMoney> _handler100 = std::make_shared<Handle100Money>();
    _handler100->add_next(_handler50);

    std::shared_ptr<HandleMoney> _handler200 = std::make_shared<Handle200Money>();
    _handler200->add_next(_handler100);

    _handler->add_next(_handler200);
}

bool ATM::get_money(unsigned value)
{
    std::cout << "Money: ";
    bool result = _handler->get_money(value);
    if(not result)
        std::cout << " no money." << std::endl;
    else
        std::cout << "." << std::endl;
    return result;
}

void ATM::update_money_of(const MoneyValue& key, unsigned value)
{
    _handler->update_money_of(key, value);
}

unsigned ATM::total_money() const
{
    return _handler->total_money();
}
