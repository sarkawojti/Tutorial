#include<memory>
#include<list>
#include<iostream>

/** Example-2: Mamy dwie figury geometryczne: 'Square' i 'Circle' oraz klase
               'AreaCalculator' ktora oblicza pola poszczegolnych figur **/

/** Task-2: Dodaj nowa figure 'Rectangle' i policz jej powierzchnie **/

/** Task_2 Refactoring: stworzenie interfejsu wizytatorow konkretnych figur **/
class Square;
class Circle;
class Rectangle;

class IShapeVisitor
{
public:
    ~IShapeVisitor() = default;

    virtual double visit(const Square*) = 0;
    virtual double visit(const Circle*) = 0;
    /** Task_2: rozszerzenie interfejsu pozwalajaca na dostep wizytatora do nowej klasy 'Rectangle' **/
    virtual double visit(const Rectangle*) = 0;
};

/** Task_2 Refactoring: stworzenie interfejsu pozwalajacego na dostep wizytatorow do konkretnych figur **/
class IAcceptShapeVisitor
{
public:
    ~IAcceptShapeVisitor() = default;

    virtual double accept(const std::shared_ptr<IShapeVisitor>&) = 0;
};

/** Task_2 Refactoring: dodanie metody dostepu wizytatorow do kazdej figury **/
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

    /** Task_2 Refactoring: dopuszczenie obiektu klasy wizytator do konkretnej figury **/
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

    /** Task_2 Refactoring: dopuszczenie obiektu klasy wizytator do konkretnej figury **/
    double accept(const std::shared_ptr<IShapeVisitor>& visitor)
    {
        return visitor->visit(this);
    }
};

/** Task_2: nowa klasa 'Rectangle' **/
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

/** Task_2 Refactoring: implementacja metod obliczajacych pole konkretnej figury **/
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

    /** Task_2: implementacja metody obliczajacej pole 'Rectangle' **/
    double visit(const Rectangle* shape) override
    {
        return shape->get_width() * shape->get_height();
    }
};

/** Task_2 Refactoring: uogolnienie dokonywanych czynnosci obliczeniowych na figurach **/
class Calculator
{
public:
    double operator()(const std::shared_ptr<Shape>& shape,
                      const std::shared_ptr<IShapeVisitor>& shape_visitor)
    {
        /** Task_2 Refactoring: usuniecie warunkow sprawdzajacych konkretny typ figury i
            zawolanie konkretnej metody obliczajacej pole figury geometrycznej,
            dzieki jednemu ze wzorcow projektowych **/
        return shape->accept(shape_visitor);
    }
};

/** By zrealizowac zadanie-2 [rozszerzyc dana klase] NIE dokonalismy modyfikacji w kodzie
    [przestrzeganie zasady: Open - closed Principle]. Wszelkie potrzebne zmiany w kodzie
    okreslamy mianem refactoringu [zmiana semantyczna kodu, bez zmiany jego funkcjonalnosci]
    dzieki ktoremu uzyskalismy kod spojny z zasada OCP **/

int main()
{
    std::list<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::make_shared<Square>(2));
    shapes.push_back(std::make_shared<Circle>(8));
    shapes.push_back(std::make_shared<Square>(2));
    shapes.push_back(std::make_shared<Rectangle>(2, 6));

    Calculator area_calculator;

    std::shared_ptr<IShapeVisitor> area_shape_visitor = std::make_shared<AreaShapeVisitor>();

    for(const auto& elem : shapes)
    {
        std::cout << "Area: " << area_calculator(elem, area_shape_visitor) << std::endl;
    }


}
