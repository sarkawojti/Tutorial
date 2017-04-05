#pragma once

template<class T>
class IStack
{
public:
    virtual bool isEmpty() const = 0;
    virtual unsigned size() const = 0;
    virtual void push(const T&) = 0;
    virtual T pop() = 0;
};
