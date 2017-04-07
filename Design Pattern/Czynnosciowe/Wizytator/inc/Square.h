#pragma once

#include "Shape.h"

class AreaVisitor;

class Square : public Shape
{
private:
    double _a;
public:
    Square(double a): _a(a){}
    void accept(const IVisitor& visitor) const override { visitor.visit(*this); };

    friend AreaVisitor;
};
