#include <iostream>
#include <memory>
#include <list>

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
    double get_width()
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
    double get_width()
    {
        return _width;
    }

    double get_height()
    {
        return _height;
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
        /** Task_2: dodanie nowego warunku do istniejacego kodu **/
        if(dynamic_cast<Rectangle*>(&*shape))
        {
            return static_cast<Rectangle*>(&*shape)->get_width()  *
                   static_cast<Rectangle*>(&*shape)->get_height() /
                   2;
        }
        throw std::string("Unexpected shape");
    }
};

/** Task_2: dodanie nowej figury 'Rectangle' do algorytmu oblicznia pola figur **/

/** By zrealizowac zadanie [rozszerzyc dana klase] dokonalismy 1 modyfikacji w [nieczytelnym] kodzie
    [zlamanie zasady: Open - closed Principle] **/

int main()
{
    std::list<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::make_shared<Square>(2));
    shapes.push_back(std::make_shared<Circle>(8));
    shapes.push_back(std::make_shared<Square>(2));
    shapes.push_back(std::make_shared<Rectangle>(2, 6));

    AreaCalculator area_calculator;

    for(const auto& elem : shapes)
    {
        std::cout << "Area:" << area_calculator(elem) << std::endl;
    }

    return 0;
}
