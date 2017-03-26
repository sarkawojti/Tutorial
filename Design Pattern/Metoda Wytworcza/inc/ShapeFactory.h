#pragma once

#include "IShapeFactory.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Square.h"

class ShapeFactory : public IShapeFactory
{
public:
    std::shared_ptr<IShape> create(const ShapeType&) override;
};

std::shared_ptr<IShape> ShapeFactory::create(const ShapeType& type)
{
    switch(type)
    {
    case ShapeType::RECTANGLE: return std::make_shared<Rectangle>(Rectangle());
    case ShapeType::TRIANGLE:  return std::make_shared<Triangle>(Triangle());
    case ShapeType::SQUARE:    return std::make_shared<Square>(Square());
    default:                   return nullptr;
    }
}
