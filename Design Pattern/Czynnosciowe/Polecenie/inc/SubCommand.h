
#pragma once

#include "Command.h"

template<class T>
class SubCommand : public Command<T, T(Calculator<T>::*)(const T&, const T&) const, Calculator<T>>
{
public:
    SubCommand(): Command<T, T(Calculator<T>::*)(const T&, const T&) const, Calculator<T>>
        (calculator, &Calculator<T>::sub)
    {
    }
private:
    Calculator<T> calculator;
};
