
#include "IIStack.h"
#include "Stack.h"

template<class T>
/** dziedziczy wielkrotnie: prywatnie z ADAPTEE i publicznie z TARGET **/
class StackClassAdapter : virtual public IIStack<T>, virtual private Stack<T>
{
public:
    bool is_empty() const override;
    unsigned num_of_elem() const override;
    void push_elem(const T&) override;
    T pop_elem() override;
};


template<class T>
bool StackClassAdapter<T>::is_empty() const
{
    return Stack<T>::isEmpty();
}

template<class T>
unsigned StackClassAdapter<T>::num_of_elem() const
{
    return Stack<T>::size();
}

template<class T>
void StackClassAdapter<T>::push_elem(const T& elem)
{
    Stack<T>::push(elem);
}

template<class T>
T StackClassAdapter<T>::pop_elem()
{
    return Stack<T>::pop();;
}
