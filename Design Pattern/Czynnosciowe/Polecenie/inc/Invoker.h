#pragma once

#include <memory>

#include "ICommand.h"
#include "IInvoker.h"

template<class T>
class Invoker : public IInvoker<T>
{
public:
    T invoke(const T& param_1, const T& param_2) const override
    {
        if(_command)
        {
            return _command->execute(param_1, param_2);
        }
        return T();
    };
    void set_command(const std::shared_ptr<ICommand<T>>& command) override
    {
        _command = command;
    }

private:
    std::shared_ptr<ICommand<T>> _command = nullptr;
};
