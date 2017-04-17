#include <iostream>
#include <memory>

class ITextField
{
public:
    virtual void set_text(const std::string&) = 0;
    virtual std::string get_text() const = 0;

    virtual ~ITextField() = default;
};

class TextField : public ITextField
{
    std::string _text;

    /** Task_1 : dodanie nowego pola informujacej czy klasa jest typu: Read Only **/
    bool _is_read_only;

public:
    /** Task_1: utowrzenie domyslnego konstruktora - ustawiajacego
        wartosc '_text' i nowe pole '_is_read_only' **/
    TextField(const std::string& text = "",
              bool is_read_only = false)
        : _text(text),
          _is_read_only(is_read_only)
    {
    }

    void set_text(const std::string& text) override
    {
        /** Task_1: dodanie logiki zwiazanej z brakiem mozliwosci zapisu zmiennej **/
        if(_is_read_only)
        {
            throw std::string("Read only.");
        }
        _text = text;
    }

    std::string get_text() const override
    {
        return _text;
    }
};

/** Task_1: Dodaj mozliwosc tworzenia klasy pola tekstowego tylko do odczytu [Read only]. **/

/** By zrealizowac zadanie [rozszerzyc dana klase] dokonalismy 3 modyfikacji w kodzie
    [zlamanie zasady: Open - closed Principle] **/


class Shape
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
    unsigned get_width()
    {
        return _width;
    }
};

class Triangle : public Shape
{
    unsigned _width;
    unsigned _height;
public:
    Triangle(unsigned width, unsigned height)
        : _width(width), _height(height)
    {
    }
    unsigned get_width()
    {
        return _width;
    }

    unsigned get_height()
    {
        return _height;
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
    unsigned get_width()
    {
        return _width;
    }

    unsigned get_height()
    {
        return _height;
    }
};

class AreaCalculator
{
public:
    unsigned area(const std::shared_ptr<Shape>& shape)
    {
        if(dynamic_cast<Square*>(&*shape))
        {
            return static_cast<Square*>(&*shape)->get_width() *
                   static_cast<Square*>(&*shape)->get_width();
        }

        if(dynamic_cast<Triangle*>(&*shape))
        {
            return static_cast<Triangle*>(&*shape)->get_width()  *
                   static_cast<Triangle*>(&*shape)->get_height() /
                   2;
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

/** By zrealizowac zadanie [rozszerzyc dana klase] dokonalismy 1 modyfikacji w kodzie
    [zlamanie zasady: Open - closed Principle] **/

int main()
{
    TextField text_field;
    text_field.set_text("Your name:");
    text_field.set_text("Your age:");

    TextField read_only_text_field("Your name:", true);
    try{
        read_only_text_field.set_text("Your age:");
    }
    catch(const std::string& exeption){
        std::cout << exeption << std::endl;
    }

    AreaCalculator area_calculator;

    std::cout << "Area Square:" << area_calculator.area(std::make_shared<Square>(2)) <<std::endl;
    std::cout << "Area Rectangle:" << area_calculator.area(std::make_shared<Rectangle>(2,5)) <<std::endl;

    return 0;
}
