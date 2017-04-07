#pragma once

#include "boost/variant.hpp"
#include "Object.h"

class TypeInfoVisitor : public boost::static_visitor<void>
{
public:
    void operator()(const int&);
    void operator()(const Object&);
    void operator()(const double&);
    void operator()(const std::string&);
};
