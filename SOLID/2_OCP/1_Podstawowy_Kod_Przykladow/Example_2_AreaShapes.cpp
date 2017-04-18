
#include <iostream>
#include <memory>
#include <list>

/**
    Example-2: Aplikacja zawiera mozliwosc tworzenia dwoch figur : 'Square' i 'Circle'
        oraz klase umozliwiajaca oblicznie pol powierzchni figur.
**/

class Shape
{
public:
    virtual ~Shape() = default;
};

class Square : public Shape
{
    double _width;
public:
    Square(double width)
        : _width(width)
    {
    }
    double get_width() const
    {
        return _width;
    }
};

class Circle : public Shape
{
    double _radius;
public:
    Circle(double radius)
        : _radius(radius)
    {
    }

    double get_radius() const
    {
        return _radius;
    }
};

class AreaCalculator
{
public:
    double operator()(const std::shared_ptr<Shape>& shape)
    {
        if(dynamic_cast<Square*>(&*shape))
        {
            return static_cast<Square*>(&*shape)->get_width() *
                   static_cast<Square*>(&*shape)->get_width();
        }

        if(dynamic_cast<Circle*>(&*shape))
        {
            return static_cast<Circle*>(&*shape)->get_radius() *
                   static_cast<Circle*>(&*shape)->get_radius() *
                   3.14;
        }
        throw std::string("Unexpected shape");
    }
};

int main()
{
    std::list<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::make_shared<Square>(2));
    shapes.push_back(std::make_shared<Circle>(8));
    shapes.push_back(std::make_shared<Square>(2));

    AreaCalculator area_calculator;

    for(const auto& elem : shapes)
    {
        std::cout << "Area:" << area_calculator(elem) << std::endl;
    }

    return 0;
}
