
#include "../inc/AreaVisitor.h"

void AreaVisitor::visit(const Rectangle& shape) const
{
    std::cout << "Area rectangle : " << shape._a * shape._b << "." << std::endl;
}

void AreaVisitor::visit(const Square& shape) const
{
    std::cout << "Area square : " << shape._a * shape._a << "." << std::endl;
}

void AreaVisitor::visit(const Triangle& shape) const
{
    std::cout << "Area triangle : " << shape._a * shape._h / 2 << "." << std::endl;
}
