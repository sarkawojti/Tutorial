#include<memory>
#include<list>
#include<iostream>

/** Example-3: Baza jest Example-2 **/

/** Task_3: dodanie nowej funkcjonalnosci obliczajacej obwod figur **/

class Square;
class Circle;
class Rectangle;

class IShapeVisitor
{
public:
    ~IShapeVisitor() = default;

    virtual double visit(const Square*) = 0;
    virtual double visit(const Circle*) = 0;
    virtual double visit(const Rectangle*) = 0;
};

class IAcceptShapeVisitor
{
public:
    ~IAcceptShapeVisitor() = default;
    virtual double accept(const std::shared_ptr<IShapeVisitor>&) = 0;
};

class Shape : public IAcceptShapeVisitor
{
public:
    virtual ~Shape() = default;
};

class Square : public Shape
{
    unsigned _width;
public:
    Square(unsigned width)
        : _width(width)
    {
    }

    unsigned get_width() const
    {
        return _width;
    }

    double accept(const std::shared_ptr<IShapeVisitor>& visitor) override
    {
        return visitor->visit(this);
    }
};

class Circle : public Shape
{
    unsigned _radius;
public:
    Circle(unsigned radius)
        : _radius(radius)
    {
    }

    unsigned get_radius() const
    {
        return _radius;
    }

    double accept(const std::shared_ptr<IShapeVisitor>& visitor)
    {
        return visitor->visit(this);
    }
};

class Rectangle : public Shape
{
    unsigned _width;
    unsigned _height;
public:
    Rectangle(unsigned width, unsigned height)
        : _width(width), _height(height)
    {
    }

    unsigned get_width() const
    {
        return _width;
    }

    unsigned get_height() const
    {
        return _height;
    }

    double accept(const std::shared_ptr<IShapeVisitor>& visitor) override
    {
        return visitor->visit(this);
    }
};

class AreaShapeVisitor : public IShapeVisitor
{
public:
    double visit(const Square* shape) override
    {
        return shape->get_width() * shape->get_width();
    }

    double visit(const Circle* shape) override
    {
        return shape->get_radius() * shape->get_radius() * 3.14;
    }

    double visit(const Rectangle* shape) override
    {
        return shape->get_width() * shape->get_height();
    }
};

/** Task-3: dodanie klasy obliczajacej obwod figur **/
class PerimeterShapeVisitor : public IShapeVisitor
{
public:
    double visit(const Square* shape) override
    {
        return 4* shape->get_width();
    }

    double visit(const Circle* shape) override
    {
        return 2* shape->get_radius() * 3.14;
    }

    double visit(const Rectangle* shape) override
    {
        return 2* shape->get_width() + 2*  shape->get_height();
    }
};

class Calculator
{
public:
    double operator()(const std::shared_ptr<Shape>& shape,
                      const std::shared_ptr<IShapeVisitor>& shape_visitor)
    {
        return shape->accept(shape_visitor);
    }
};

int main()
{
    std::list<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::make_shared<Square>(2));
    shapes.push_back(std::make_shared<Circle>(8));
    shapes.push_back(std::make_shared<Square>(2));
    shapes.push_back(std::make_shared<Rectangle>(2, 6));

    Calculator calculator;

    std::shared_ptr<IShapeVisitor> area_shape_visitor = std::make_shared<AreaShapeVisitor>();

    std::shared_ptr<IShapeVisitor> perimeter_shape_visitor = std::make_shared<PerimeterShapeVisitor>();

    for(const auto& elem : shapes)
    {
        std::cout << "Area:" << calculator(elem, area_shape_visitor) << std::endl;
        std::cout << "Perimeter:" << calculator(elem, perimeter_shape_visitor) << std::endl;
    }
}
