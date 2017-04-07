
#pragma once

#include <iostream>

template<class T>
class Calculator
{

public:
   T add(const T&, const T&) const;
   T sub(const T&, const T&) const;
};

template<class T>
T Calculator<T>::add(const T& param1, const T& param2) const
{
    return param1 + param2;
}

template<class T>
T Calculator<T>::sub(const T& param1, const T& param2) const
{
    return param1 - param2;
}
