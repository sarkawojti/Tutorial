#pragma once

#include "ICommand.h"

template<class T, class Action, class Reciver>
class Command : public ICommand<T>
{

public:

    Command(Reciver& reciver, Action action) :
        _reciver(reciver),
        _action(action)
    {
    }

    T execute(const T& param_1, const T& param_2) const override
    {
        return (_reciver.*_action)(param_1, param_2);
    };

protected:
    Reciver& _reciver;
    Action _action;
};
