#include <iostream>
#include <memory>

class ITextField
{
public:
    virtual void set_text(const std::string&) = 0;
    virtual std::string get_text() const = 0;

    virtual ~ITextField() = default;
};

class TextField
{
    std::string _text;

public:
    void set_text(const std::string& text)
    {
        _text = text;
    }

    std::string get_text() const
    {
        return _text;
    }
};

/** Task_1: stworzenie nowej klasy w oparciu o jeden z wzorcow projektowych **/
class TextFieldReadOnly : public ITextField
{
    TextField textField;
public:
    TextFieldReadOnly(const std::string& text)
    {
        textField.set_text(text);
    }

    void set_text(const std::string& text) override
    {
        throw std::string("Read only.");
    }

    std::string get_text() const override
    {
        return textField.get_text();
    }
};

/** Task_1: Dodaj mozliwosc tworzenia klasy pola tekstowego tylko do odczytu [Read only]. **/

/** By zrealizowac zadanie [rozszerzyc dana klase] dokonalismy 0 modyfikacji w kodzie
    [zastosowanie zasady: Open - closed Principle] **/

/** Task_2 Refactoring: dodanie interfejsu z metoda oblicznia pola figur **/
class IArea
{
public:
    virtual ~IArea() = default;

    virtual unsigned area() const = 0;
};

/** Task_2 Refactoring: dodanie interfejsu z metoda oblicznia pola figur
    do intefejsu figur **/
class Shape : public IArea
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
    /** Task_2 Refactoring: usuniecie zbednych metod dostepu do prywatnych pol figur **/
    /** Task_2 Refactoring: zaimplementowanie metody obliczajacej pole danej figury **/
    unsigned area() const override
    {
        return _width * _width;
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
    /** Task_2 Refactoring: usiniecie zbednych metod dostepu do prywatnych pol figur **/
    /** Task_2 Refactoring: zaimplementowanie metody obliczajacej pole danej figury **/
    unsigned area() const override
    {
        return _width * _height / 2;
    }
};

/** Task_2: dodanie nowej klasy 'Rectangle' **/
class Rectangle : public Shape
{
    unsigned _width;
    unsigned _height;
public:
    Rectangle(unsigned width, unsigned height)
        : _width(width), _height(height)
    {
    }

    unsigned area() const override
    {
        return _width * _height;
    }
};

class AreaCalculator
{
public:
    unsigned area(const std::shared_ptr<Shape>& shape)
    {
        /** Task_2 Refactoring: usuniecie warunkow sprawdzajacych konkretny typ figury i
            zawolanie konkretnej metody obliczajacej pole figury geometrycznej **/
        return shape->area();
    }
};

/** Task_2: dodanie nowej figury 'Rectangle' do algorytmu oblicznia pola figur **/

/** By zrealizowac zadanie [rozszerzyc dana klase] dokonalismy 0 modyfikacji w kodzie
    [przestrzeganie zasady: Open - closed Principle]. Wszelkie potrzebne zmiany w kodzie
    okreslamy mianem refactoringu [zmiana semantyczna kodu, bez zmiany jego funkcjonalnosci]
    dzieki ktoremu uzyskalismy kod spojny z zasada OCP **/

int main()
{
    TextField text_field;
    text_field.set_text("Your name:");
    text_field.set_text("Your age:");

    TextFieldReadOnly read_only_text_field("Your name:");
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

