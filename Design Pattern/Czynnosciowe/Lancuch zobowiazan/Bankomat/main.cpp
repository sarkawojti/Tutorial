
#include "inc/ATM.h"

#include <cassert>

int main()
{
    ATM _atm;

    assert(_atm.total_money() == 0);

    _atm.update_money_of(MoneyValue::VALUE_500, 2);
    _atm.update_money_of(MoneyValue::VALUE_200, 5);
    _atm.update_money_of(MoneyValue::VALUE_100, 10);
    _atm.update_money_of(MoneyValue::VALUE_50,  20);
    _atm.update_money_of(MoneyValue::VALUE_20,  50);
    _atm.update_money_of(MoneyValue::VALUE_10,  100);
    assert(_atm.total_money() == 6000);

    assert(_atm.get_money(7000)== false);
    assert(_atm.total_money() == 6000);
    assert(_atm.get_money(2000)== true);
    assert(_atm.total_money() == 4000);
    assert(_atm.get_money(3660)== true);
    assert(_atm.total_money() == 340);
    assert(_atm.get_money(350)== false);

    _atm.update_money_of(MoneyValue::VALUE_20,  1);
    assert(_atm.total_money() == 360);
    assert(_atm.get_money(350)== true);
    assert(_atm.total_money() == 10);
    _atm.update_money_of(MoneyValue::VALUE_50,  1);
    assert(_atm.total_money() == 60);
    assert(_atm.get_money(20)== false);
    assert(_atm.get_money(40)== false);
    assert(_atm.get_money(50)== true);

    return 0;
}
