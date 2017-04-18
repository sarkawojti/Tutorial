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

    /** Task_1 : dodanie nowego pola informujacego czy klasa jest typu: Read Only **/
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

/** By zrealizowac zadanie [rozszerzyc dana klase] dokonalismy modyfikacji w kodzie
    [zlamanie zasady: Open - closed Principle] **/

int main()
{
    std::shared_ptr<ITextField> text_field =
        std::make_shared<TextField>();
    text_field->set_text("Your name:");
    text_field->set_text("Your age:");

    std::shared_ptr<ITextField> read_only_text_field =
        std::make_shared<TextField>("Your name:", true);

    try{
        read_only_text_field->set_text("Your age:");
    }
    catch(const std::string& exeption){
        std::cout << exeption << std::endl;
    }
}
