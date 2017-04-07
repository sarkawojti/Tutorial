#pragma once

class Square;
class Triangle;
class Rectangle;

class IVisitor
{
public:
    virtual ~IVisitor() = default;

    virtual void visit(const Square&)    const = 0;
    virtual void visit(const Triangle&)  const = 0;
    virtual void visit(const Rectangle&) const = 0;
};
