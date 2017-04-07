#pragma once

#include <iostream>

#include "IVisitor.h"

#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

class AreaVisitor : public IVisitor
{

public:
    void visit(const Rectangle&) const override;
    void visit(const Square&)    const override;
    void visit(const Triangle&)  const override;
};
