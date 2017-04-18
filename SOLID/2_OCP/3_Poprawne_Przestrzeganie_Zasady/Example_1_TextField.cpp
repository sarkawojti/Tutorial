#include <iostream>
#include <memory>
#include <cassert>

/** Task_1: Dodaj mozliwosc tworzenia klasy pola tekstowego tylko do odczytu [Read only]. **/

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

public:
    void set_text(const std::string& text) override
    {
        _text = text;
    }

    std::string get_text() const override
    {
        return _text;
    }
};

/** Task-1: utworzenie nowej klasy reprezentujacej pole tekstowe tylko
        do odczytu, w oparciu o jeden z wzorcow projektowych **/
class TextFieldReadOnly : public ITextField
{
    std::shared_ptr<ITextField> _textField;
public:
    TextFieldReadOnly(const std::shared_ptr<ITextField>& textField)
    {
        _textField = textField;
    }

    void set_text(const std::string& text) override
    {
        throw std::string("Read only.");
    }

    std::string get_text() const override
    {
        return _textField->get_text();
    }
};

/** By zrealizowac zadanie [rozszerzyc dana klase] NIE dokonalismy
    modyfikacji w kodzie [zastosowanie zasady: Open - closed Principle] **/

int main()
{
    std::shared_ptr<ITextField> text_field = std::make_shared<TextField>();

    assert("" == text_field->get_text());

    text_field->set_text("Your name:");
    assert("Your name:" == text_field->get_text());

    text_field->set_text("Your age:");
    assert("Your age:" == text_field->get_text());

    std::shared_ptr<ITextField> read_only_text_field = std::make_shared<TextFieldReadOnly>(text_field);

    try{
        read_only_text_field->set_text("Your age:");
    }
    catch(const std::string& exeption){
        std::cout << exeption << std::endl;
    }
}
