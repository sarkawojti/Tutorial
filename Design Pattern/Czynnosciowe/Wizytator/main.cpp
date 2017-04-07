
#include <vector>
#include <memory>


#include "inc/Rectangle.h"
#include "inc/Square.h"
#include "inc/Triangle.h"

#include "inc/CountVisitor.h"
#include "inc/AreaVisitor.h"

int main()
{
    std::vector<std::shared_ptr<IShape>> _shapes =
    {
        std::make_shared<Rectangle>(2, 6),
        std::make_shared<Triangle>(2, 5),
        std::make_shared<Triangle>(3, 4),
        std::make_shared<Square>(4),
        std::make_shared<Rectangle>(3, 8),
        std::make_shared<Triangle>(1, 3),
        std::make_shared<Triangle>(3, 5)
    };

    CountVisitor _counter;
    AreaVisitor  _area;

    for(const auto& item : _shapes)
    {
        (*item).accept(_area);
        (*item).accept(_counter);
    }

    std::cout << std::endl;
    std::cout << _counter <<std::endl;
}
