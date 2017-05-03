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

    text_field->set_text("Your name:");
    text_field->set_text("Your age:");
}

