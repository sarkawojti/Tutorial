
#include "../inc/HandleMoney.h"
#include <iostream>
#include <sstream>

void HandleMoney::add_next(const std::shared_ptr<IHandleMoney>& handler)
{
    _next = handler;
}

bool HandleMoney::get_money(unsigned value)
{
    unsigned need_num_of = value/(int)money_value;
    unsigned tmp_num_of;
    std::ostringstream cash;

    if(_num_of > need_num_of)
    {
        value -= need_num_of * (int)money_value;
        cash << need_num_of << "*" << (int)money_value << "  ";
        tmp_num_of = _num_of - need_num_of;
    }
    else
    {
        value -= _num_of*(int)money_value;
        cash << _num_of << "*" << (int)money_value << "  ";
        tmp_num_of = 0;
    }

    if(0 == value)
    {
        _num_of = tmp_num_of;
        std::cout << cash.str();
        return true;
    }

    if(_next and
       _next->get_money(value))
    {
        std::cout << cash.str();
        _num_of = tmp_num_of;
        return true;
    }
    return false;
}

void HandleMoney::update_money_of(const MoneyValue& searach_key, unsigned num_of)
{
   if(searach_key == money_value)
    {
        _num_of = num_of;
        return;
    }
    if(_next)
    {
        _next->update_money_of(searach_key, num_of);
    }
}

unsigned HandleMoney::total_money() const
{
    unsigned result = _num_of * (int)money_value;
    if(_next)
    {
        result += _next->total_money();
    }
    return result;
}


