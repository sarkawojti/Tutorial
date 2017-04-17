#include<string>
#include <regex>

class Person
{
    std::string _name;
    std::string  _surname;

    /** pola klasy Person: '_home_town', '_street', '_post_code',
        '_home_number', '_flat_number' NIE SA z nia scisle POWIAZANE;
        powinny zostac wydzielone do osobnej klasy **/
    std::string _home_town;
    std::string _street;
    unsigned _post_code;
    unsigned _home_number;
    unsigned _flat_number;

    std::string _email;

    /** metoda klasy Person odpowiedzialna za walidacje poprawnosci
        adresu e-mail NIE POWINNA znajdowac sie w zakresie jej obowiazkow;
        powinna  zostac wydzielona do osobnej klasy **/
    bool validate_email(const std::string& email) const
    {
        if(std::regex_match(email, std::regex("(.+)(@)(.+)(.)(.+)")));
        {
            return true;
        }
        /** metoda klasy Person POWINNA byc ODPOWIEDZIALNA za JEDNA rzecz -
            dokonanie walidacji poprawnosci formatu zmiennej 'email';
            dodatkowy obowiazek - rzucanie wyjatku powinien zostac przenisiony
            do wyzszej warstwy kodu **/
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
        /** konstruktor klasy Person nie powinien walidowac poprawnosci dostarczonych
            danych a zajmowac sie swoim obowiazkiem - tworzeniem konkretnych obiektow
            i rzucac wyjatki jedynie zwiazne z procesem ich kreacji;
            walidacja poprawnosci danych POWINNA znajdowac sie w wyzszych warstwach kodu**/
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

