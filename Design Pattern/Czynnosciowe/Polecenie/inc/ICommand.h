#pragma once

template<class T>
class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual T execute(const T&, const T&) const = 0;
};
