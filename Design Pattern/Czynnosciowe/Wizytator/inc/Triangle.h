#pragma once

#include "Shape.h"

class AreaVisitor;

class Triangle : public Shape
{
private:
    double _a;
    double _h;
public:
    Triangle(double a, double h): _a(a), _h(h){}
    void accept(const IVisitor& visitor) const override { visitor.visit(*this); };

    friend AreaVisitor;
};
