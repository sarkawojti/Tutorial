#pragma once

#include <iostream>

#include "IVisitor.h"

class CountVisitor : public IVisitor
{
private:
    mutable unsigned _num_of_rectangle = 0;
    mutable unsigned _num_of_square    = 0;
    mutable unsigned _num_of_triangle  = 0;

public:
    void visit(const Rectangle&) const override { _num_of_rectangle++; };
    void visit(const Square&)    const override { _num_of_square++; };
    void visit(const Triangle&)  const override { _num_of_triangle++; };

    friend std::ostream& operator<<(std::ostream&, const CountVisitor&);
};

std::ostream& operator<<(std::ostream& os, const CountVisitor& counter)
{
    os << "Statistic: num of rectangle(" << counter._num_of_rectangle
               << "), num of square("    << counter._num_of_square
               << "), num of triangle("  << counter._num_of_triangle
               << ").";
    return os;
}
