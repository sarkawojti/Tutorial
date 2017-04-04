#include <iostream>


class A
{
public:
    virtual void func(){ }
    A(){ std::cout << "A() called" << std::endl;}
    virtual ~A(){ std::cout << "~A() called" << std::endl;}
};
class B : virtual public A
{
public:
    B(){ std::cout << "B() called" << std::endl;}
    virtual ~B(){ std::cout << "~B() called" << std::endl;}
};
class C : virtual public A
{
public:
    C(){ std::cout << "C() called" << std::endl;}
    virtual ~C(){ std::cout << "~C() called" << std::endl;}
};
class D : public B, public C
{
public:
    D(){ std::cout << "D() called" << std::endl;}
    virtual ~D(){ std::cout << "~D() called" << std::endl;}
};

/**
    constructor and destructor of 'A' is called two times ->
        object 'd' has two copies of all members of 'A', this causes ambiguities.

    The solution to this problem is 'virtual' keyword. [virtual public A]
**/

int main()
{
    D d;
    d.func();
    return 0;
}
