#pragma once

#include "IVisitor.h"

class IShape
{
public:
    virtual ~IShape() = default;
    virtual void accept(const IVisitor&) const = 0;
};
