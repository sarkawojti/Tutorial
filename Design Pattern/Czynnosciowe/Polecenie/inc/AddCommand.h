#pragma once

#include "Command.h"

template<class T>
class AddCommand : public Command<T, T(Calculator<T>::*)(const T&, const T&) const, Calculator<T>>
{
public:
    AddCommand(): Command<T, T(Calculator<T>::*)(const T&, const T&) const, Calculator<T>>
        (calculator, &Calculator<T>::add)
    {
    }
private:
    Calculator<T> calculator;
};
