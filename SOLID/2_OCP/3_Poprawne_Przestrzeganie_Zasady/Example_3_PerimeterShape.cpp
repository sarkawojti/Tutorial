#include <iostream>
#include <memory>
#include <list>

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

    double accept(const std::shared_ptr<IShapeVisitor>& visitor) override
    {
        return visitor->visit(this);
    }
};

class Rectangle : public Shape
{
    double _width;
    double _height;
public:
    Rectangle(double width, double height)
        : _width(width), _height(height)
    {
    }
    double get_width() const
    {
        return _width;
    }

    double get_height() const
    {
        return _height;
    }

    double accept(const std::shared_ptr<IShapeVisitor>& visitor) override
    {
        return visitor->visit(this);
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

    double accept(const std::shared_ptr<IShapeVisitor>& visitor) override
    {
        return visitor->visit(this);
    }
};

class IAreaShapeVisitor : public IShapeVisitor
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

class Calculator
{
public:
    double operator()(const std::shared_ptr<Shape>& shape,
                      const std::shared_ptr<IShapeVisitor>& shape_visitor)
    {
        return shape->accept(shape_visitor);
    }
};

/** Task-3: dodanie klasy obliczajacej obwod figur **/
class IPerimeterShapeVisitor : public IShapeVisitor
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

/** By zrealizowac zadanie [rozszerzyc dana klase] NIE dokonalismy
    modyfikacji w kodzie [zachowanie zasady: Open - closed Principle] **/

int main()
{
    std::list<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::make_shared<Square>(2));
    shapes.push_back(std::make_shared<Circle>(8));
    shapes.push_back(std::make_shared<Square>(2));
    shapes.push_back(std::make_shared<Rectangle>(2, 6));

    Calculator area_calculator;

    std::shared_ptr<IShapeVisitor> area_shape_visitor =
        std::make_shared<IAreaShapeVisitor>();
    std::shared_ptr<IShapeVisitor> perimeter_shape_visitor =
        std::make_shared<IPerimeterShapeVisitor>();

    for(const auto& elem : shapes)
    {
        std::cout << "Area:" << area_calculator(elem, area_shape_visitor) << std::endl;
        std::cout << "Perimeter:" << calculator(elem, perimeter_shape_visitor) << std::endl;
    }
}

