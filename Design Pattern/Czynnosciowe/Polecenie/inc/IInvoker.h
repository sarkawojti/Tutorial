#pragma once

#include <memory>

#include "ICommand.h"

template<class T>
class IInvoker
{
public:
    virtual ~IInvoker() = default;
    virtual T invoke(const T&, const T&) const = 0;
    virtual void set_command(const std::shared_ptr<ICommand<T>>&) = 0;
};

