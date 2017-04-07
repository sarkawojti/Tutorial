#pragma once

#include "Shape.h"

class AreaVisitor;

class Rectangle : public Shape
{
private:
    double _a;
    double _b;

public:
    Rectangle(double a, double b): _a(a), _b(b){}
    void accept(const IVisitor& visitor) const override { visitor.visit(*this); };

    friend AreaVisitor;
};
