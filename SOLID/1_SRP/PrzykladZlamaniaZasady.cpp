#include<string>

class Person
{
    std::string _name;
    std::string  _surname;
    /** atrybuty zwiazane z adresem nie sa scisle powiazane z klasa Person,
       powinny zostac wydzielone do osobnej klasy **/
    std::string _home_town;
    std::string _street;
    unsigned _post_code;
    unsigned _home_number;
    unsigned _flat_number;

    std::string _email;

    /** metoda walidujaca poprawnosc adres e-mail
        nie powinna lezec w obowiazakach klasy Person **/
    bool validate_email(const std::string& email) const
    {
        if(email.find('@'))
        {
            return true;
        }
        /** funkcja walidujaca nie powinna robic kilku rzeczy a JEDNA,
            rzucanie wyjatku powinno zostac przeniesione do wyzszej warstwy **/
        throw "Wrong email format.";
        return false;
    }

public:
    Person(const std::string& name,
           const std::string& surname,
           const std::string& home_town,
           const std::string& street,
           unsigned post_code,
           unsigned home_number,
           unsigned flat_number,
           const std::string& email)
        : _name(name),
          _surname(surname),
          _home_town(home_town),
          _street(street),
          _post_code(post_code),
          _home_number(home_number),
          _flat_number(flat_number)
    {
        /** konstruktor nie powinien walidowac poprawnosci dostarczonych danych,
            dodatkowa funkcjonalnosc poza tworzeniem obiektu **/
        if(validate_email(email))
        {
            _email = email;
        }
    }
};

int main()
{
    Person jan_kowalski("Jan", "Kowalski", "Krakow", "Lea", 30056, 23, 13, "jan.kowalski@gmail.com");

    return 0;
}

