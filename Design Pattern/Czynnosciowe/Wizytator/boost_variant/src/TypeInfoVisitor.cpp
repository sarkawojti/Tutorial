#include "../inc/TypeInfoVisitor.h"

#include <iostream>

void TypeInfoVisitor::operator()(const int&)
{
    std::cout << "Current type is int" << std::endl;
}

void TypeInfoVisitor::operator()(const Object&)
{
    std::cout << "Current type is Object" << std::endl;
}

void TypeInfoVisitor::operator()(const double&)
{
    std::cout << "Current type is double" << std::endl;
}

void TypeInfoVisitor::operator()(const std::string&)
{
    std::cout << "Current type is std::string" << std::endl;
}
