#pragma once

template<class T>
class IIStack
{
public:
    virtual bool is_empty() const = 0;
    virtual unsigned num_of_elem() const = 0;
    virtual void push_elem(const T&) = 0;
    virtual T pop_elem() = 0;
};
