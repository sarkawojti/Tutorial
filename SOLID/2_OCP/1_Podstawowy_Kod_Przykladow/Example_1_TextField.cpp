#include <iostream>
#include <memory>
#include <cassert>

/**
    Example-1: Klasa reprezentujaca pole tekstowe z ktorego mozna
        odczytywac zawartosc i wstawiac nowa konkretna wartosc.
**/

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

int main()
{
    std::shared_ptr<ITextField> text_field = std::make_shared<TextField>();

    assert("" == text_field->get_text());

    text_field->set_text("Your name:");
    assert("Your name:" == text_field->get_text());

    text_field->set_text("Your age:");
    assert("Your age:" == text_field->get_text());
}
