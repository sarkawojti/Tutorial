#include<string>
#include <regex>
#include <memory>

class Address
{
    std::string _home_town;
    std::string _street;
    unsigned _post_code;
    unsigned _home_number;
    unsigned _flat_number;

public:
    Address() = default;
    Address(const std::string& home_town,
            const std::string& street,
            unsigned post_code,
            unsigned home_number,
            unsigned flat_number)
        : _home_town(home_town),
          _street(street),
          _post_code(post_code),
          _home_number(home_number),
          _flat_number(flat_number)
    {
    }
};

template<class T>
class IValidator
{
public:
    virtual bool validate(const T&) = 0;
};


class EmailValidator : public IValidator<std::string>
{
public:
    bool validate(const std::string& email)
    {
        return std::regex_match(email, std::regex("(.+)(@)(.+)(.)(.+)"));
    }
};

class Person
{
    std::string _name;
    std::string  _surname;
    Address _address;
    std::string _email;

public:
    Person(const std::string& name,
           const std::string& surname,
           const Address& address,
           const std::string& email)
        : _name(name),
          _surname(surname),
          _address(address),
          _email(email)
    {
    }
};

int main()
{
    /** SOLUTION: wydzielenie czesci niepowiazanych pol z klasy Person do klasy Address **/
    Address address("Krakow", "Lea", 30056, 23, 13);

    /** SOLUTION: Stworzenie interfejsu i klasy opdowiedzialnej za proces walidacji danych **/
    std::shared_ptr<IValidator<std::string>> validator = std::make_shared<EmailValidator>();
    std::string email = "jan.kowalski@gmail.com";
    /** SOLUTION: walidacja poprawosci danych w wyzszej warstwie kodu;
        [przed proba stworzenia obiektu, zaraz za stworzeniem zmiennej] **/
    if(not validator->validate(email))
    {
        /** SOLUTION: rzucanie wyjatku przez wyzsza warstwe kodu **/
        throw "Wrong email format.";
    }

    Person jan_kowalski("Jan", "Kowalski", address, email);

    return 0;
}


