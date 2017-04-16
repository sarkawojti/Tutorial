#include<string>

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

class EmailValidator
{
public:
    bool validate(const std::string& email)
    {
        return (email.find('@'));
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
    /** wydzielenie czesci niepowiazanych danych z obiektem do osobnej klasy **/
    Address address("Krakow", "Lea", 30056, 23, 13);

    /** wyjecie metody walidujacej do osobnej klasy **/
    EmailValidator email_validator;
    std::string email = "jan.kowalski@gmail.com";
    /** walidacja poprawosci danych przed stworzeniem obiektu **/
    if(not email_validator.validate(email))
    {
        /** rzucanie wyjatku przed tworzeniem obiektu **/
        throw "Wrong email format.";
    }

    Person jan_kowalski("Jan", "Kowalski", address, email);

    return 0;
}


