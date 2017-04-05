#pragma once

#include "Stack.h"

#include <deque>

template<class T>
/** dziedziczy interfejs docelowy **/
class Stack : public IStack<T>
{
public:
    bool isEmpty() const override;
    unsigned size() const override;
    void push(const T&) override;
    T pop() override;

private:
    /** przechowuje odwolanie umozliwiajace dostep do ADAPTEE **/
    std::deque<T> _stack;
};

template<class T>
bool Stack<T>::isEmpty() const
{
    return _stack.empty();
}

template<class T>
unsigned Stack<T>::size() const
{
    return _stack.size();
}

template<class T>
void Stack<T>::push(const T& elem)
{
    _stack.push_back(elem);
}

template<class T>
T Stack<T>::pop()
{
    const T elem = _stack.back();
    _stack.pop_back();
    return elem;
}
