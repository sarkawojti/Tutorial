#pragma once

#include <memory>

#include "IShape.h"
#include "ShapeTypes.h"

class IShapeFactory
{
public:
    virtual std::shared_ptr<IShape> create(const ShapeType&) = 0;

    virtual ~IShapeFactory() = default;
};
