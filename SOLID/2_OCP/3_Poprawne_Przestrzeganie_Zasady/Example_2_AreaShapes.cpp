
#include <iostream>
#include <memory>
#include <list>

/** Task_2: dodanie nowej figury 'Rectangle' do algorytmu oblicznia pola figur **/

/** Realizacja tego zadania wymaga wczesniejszego Refactoringu dostosowujacego zastany kod do zasady OCP **/

/** Refactoring: utworzenie interfejsu dla wizytatorow figur **/
class Square;
class Circle;
class Rectangle;

class IShapeVisitor
{
public:
    ~IShapeVisitor() = default;

    virtual double visit(const Square*) = 0;
    virtual double visit(const Circle*) = 0;
    /** Task-2 dodanie kolejnej funkcji dopuszczajacej danego wizytaora**/
    virtual double visit(const Rectangle*) = 0;
};

class IAcceptShapeVisitor
{
public:
    ~IAcceptShapeVisitor() = default;
    virtual double accept(const std::shared_ptr<IShapeVisitor>&) = 0;
};

/**Refactoring: dodanie metody dostepu wizytatorow do kazdej figury **/
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
    /** Refactoring: dopuszczenie obiektu klasy wizytator do skladowych publicznych konkretnej figury **/
    double accept(const std::shared_ptr<IShapeVisitor>& visitor) override
    {
        return visitor->visit(this);
    }
};

/** Task-2: Dodanie nowej figury 'Rectangle' **/
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
    /** Refactoring: dopuszczenie obiektu klasy wizytator do skladowych publicznych konkretnej figury **/
    double accept(const std::shared_ptr<IShapeVisitor>& visitor) override
    {
        return visitor->visit(this);
    }
};

/** Refactoring: implementacja metod obliczajacych pole konkretnej figury **/
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

    /** Task_2: implementacja metody obliczajacej pole 'Rectangle' **/
    double visit(const Rectangle* shape) override
    {
        return shape->get_width() * shape->get_height();
    }
};

/** Refactoring: uogolnienie dokonywanych czynnosci obliczeniowych na figurach **/
class /*Area*/Calculator
{
public:
    double operator()(const std::shared_ptr<Shape>& shape,
                      const std::shared_ptr<IShapeVisitor>& shape_visitor)
    {
        /** Refactoring: usuniecie warunkow sprawdzajacych konkretny typ figury i
            zawolanie konkretnej metody obliczajacej pole figury geometrycznej,
            dzieki jednemu ze wzorcow projektowych **/
        return shape->accept(shape_visitor);
        /*if(dynamic_cast<Square*>(&*shape))
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
        throw std::string("Unexpected shape");*/
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

    for(const auto& elem : shapes)
    {
        std::cout << "Area:" << area_calculator(elem, area_shape_visitor) << std::endl;
    }
}
